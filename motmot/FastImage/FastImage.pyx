#emacs, this is -*-Python-*- mode

# indexing starts from left, bottom

cimport libc.stdlib
cimport libc.stdio
cimport libc.string
import traceback, sys
cimport numpy
import numpy

cdef int FASTIMAGEDEBUG
FASTIMAGEDEBUG = 0

numpy.import_array()

# create char types that work in Pyrex and Cython
cdef char CHAR_u
CHAR_u = ord('u')
cdef char CHAR_f
CHAR_f = ord('f')

# for computing histograms
cdef int n_hist_levels
n_hist_levels = 256
cdef ipp.Ipp32s hist_levels[257]
for i in range(0,257):
    hist_levels[i]=i

def set_debug(int val):
    global FASTIMAGEDEBUG
    FASTIMAGEDEBUG = val

cdef extern from "unistd.h":
    ctypedef unsigned long intptr_t

cdef extern from "limits.h":
    cdef intptr_t INT_MAX
    cdef intptr_t INT_MIN

cdef extern from "FastImage_macros.h":
    # for PyArrayInterface
    int CONTIGUOUS
    int FORTRAN
    int ALIGNED
    int NOTSWAPPED
    int WRITEABLE
    int ARR_HAS_DESCR

    # for IPP
    ipp.Ipp8u*  IMPOS8u(  ipp.Ipp8u*  im, int step, int bottom, int left)
    ipp.Ipp32f* IMPOS32f( ipp.Ipp32f* im, int step, int bottom, int left)
    void CHK_NOGIL( ipp.IppStatus errval )

    const char* ippGetStatusString( ipp.IppStatus StsCode )

    cdef void InitIPP()

    ctypedef struct ipp_version_struct_t:
        int major
        int minor
        int build

    cdef ipp_version_struct_t GetIPPVersion()
    cdef const char* GetIPPArch()
    cdef int IsIPPStatic()

InitIPP()

def get_IPP_version():
    cdef ipp_version_struct_t val
    val = GetIPPVersion()
    return val.major, val.minor, val.build

def get_IPP_arch():
    cdef const char* arch_str
    arch_str = GetIPPArch()
    return arch_str

def get_IPP_static():
    return IsIPPStatic()

class IppError(Exception):
    def __init__(self, int errval):
        cdef const char* cmsg
        cmsg = ippGetStatusString(<ipp.IppStatus>errval)
        #Exception.__init__(self,"Error %d: %s"%(errval,cmsg))
        Exception.__init__(self,cmsg)

class FicError(Exception):
    pass

cdef void CHK_HAVEGIL( ipp.IppStatus errval ) except *:
    if (errval!=0):
        raise IppError(errval)

cdef void CHK_FIC_HAVEGIL( fic.FicStatus errval ) except *:
    if (errval!=0):
        errstr = fic.ficGetErrorString(errval)
        raise FicError('error %d: %s'%(errval,errstr))

ctypedef struct PyArrayInterface:
    int two                       # contains the integer 2 as a sanity check
    int nd                        # number of dimensions
    char typekind                 # kind in array --- character code of typestr
    int itemsize                  # size of each element
    int flags                     # flags indicating how the data should be interpreted
    numpy.Py_intptr_t *shape   # A length-nd array of shape information
    numpy.Py_intptr_t *strides # A length-nd array of stride information
    void *data                    # A pointer to the first element of the array

cdef void free_array_struct( void* ptr, void *arr ):
    arrpy = <object>arr
    cpython.ref.Py_DECREF( arrpy )
    libc.stdlib.free(ptr)

# comparision operators
CmpLess = ipp.ippCmpLess
CmpLessEq = ipp.ippCmpLessEq
CmpEq = ipp.ippCmpEq
CmpGreaterEq = ipp.ippCmpGreaterEq
CmpGreater = ipp.ippCmpGreater

cdef class Size:
    """size of 2D image

    sz=Size(width,height)
    """
    # keep this read-only to prevent bizarre problems if multiple image share same size
    def __init__(self,int width,int height):
        self.sz.width = width
        self.sz.height = height
    def __repr__(self):
        return 'FastImage.Size(%d,%d)'%(self.sz.width,self.sz.height)
    def __richcmp__(x, y, int op):
        cdef Size xs
        cdef Size ys
        if type(x) != Size:
            raise TypeError("comparison between Size objects only")
        if type(y) != Size:
            raise TypeError("comparison between Size objects only")
        xs = x
        ys = y
        if op==2:
            return xs.sz.width == ys.sz.width and xs.sz.height == ys.sz.height
        elif op==3:
            return not (xs.sz.width == ys.sz.width and xs.sz.height == ys.sz.height)
        else:
            raise ValueError("cannot perform comparison (equality testing only)")

    # leave as short names to make life easy when looking for .sz.width (fast C) vs. .w (slow Python)
    property h:
        def __get__(self):
            return self.sz.height
    property w:
        def __get__(self):
            return self.sz.width

cdef class Point:
    # keep this read-only to prevent bizarre problems if multiple image share same origin
    def __init__(self,int x,int y):
        self.pt.x = x
        self.pt.y = y
    def __repr__(self):
        return 'FastImage.Point(%d,%d)'%(self.pt.x,self.pt.y)
    def __richcmp__(a, b, int op):
        cdef Point ap
        cdef Point bp
        if type(a) != Point:
            raise TypeError("comparison between Point objects only")
        if type(b) != Point:
            raise TypeError("comparison between Point objects only")
        ap = a
        bp = b
        if op==2:
            return ap.pt.x == bp.pt.x and ap.pt.y == bp.pt.y
        elif op==3:
            return not (ap.pt.x == bp.pt.x and ap.pt.y == bp.pt.y)
        else:
            raise ValueError("cannot perform comparison (equality testing only)")

    # leave as short names to make life easy when looking for .sz.width (fast C) vs. .w (slow Python)
    property x:
        def __get__(self):
            return self.pt.x
    property y:
        def __get__(self):
            return self.pt.y

cdef class FastImageBase:
    def __cinit__(self,*args,**kw):
        self.view = 1

    def __init__(self, Size size):
        self.imsiz = size

        # purely for making __array_struct__ without extra malloc:
        self.shape[0] = size.sz.height
        self.shape[1] = size.sz.width

    def __dealloc__(self):
        global FASTIMAGEDEBUG
        if self.view==0:
            if FASTIMAGEDEBUG>=1:
                print self,'freeing memory %#x'%<intptr_t>self.im
            ipp.ippiFree(self.im)

    def show_mem_and_step(self):
        print self,'got mem %#x step %d'%(<intptr_t>self.im,
                                          self.step)

    def stringview(self):
        cdef int i,j
        cdef fiptr rowptr
        cdef fiptr valptr
        lines = []
        for i from 0 <= i < self.imsiz.sz.height:
            line = []
            rowptr = self.im+i*self.step
            for j from 0 <= j < self.imsiz.sz.width:
                valptr = rowptr+j*self.strides[1]
                if self.basetype == '8u':
                    line.append((<ipp.Ipp8u*>valptr)[0])
                elif self.basetype == '32f':
                    line.append((<ipp.Ipp32f*>valptr)[0])
            line = ' '.join(map(str,line))
            lines.append(line)
        lines = '\n'.join(lines)
        return lines

    property _step:
        def __get__(self):
            return self.step

    property __array_struct__:
        def __get__(self):
            cdef PyArrayInterface* inter

            inter = <PyArrayInterface*>libc.stdlib.malloc( sizeof( PyArrayInterface ) )
            inter.two = 2
            inter.nd = 2
            if self.basetype == '8u':
                inter.typekind = CHAR_u
            elif self.basetype == '32f':
                inter.typekind = CHAR_f
            else:
                raise ValueError('unknown basetype: %r'%self.basetype)
            inter.itemsize = self.strides[1]
            inter.flags = NOTSWAPPED | ALIGNED | WRITEABLE
            inter.strides = self.strides
            inter.shape = self.shape
            inter.data = self.im
            cpython.ref.Py_INCREF(self)
            obj = cpython.cobject.PyCObject_FromVoidPtrAndDesc( <void*>inter, <void*>self, free_array_struct)
            return obj

    property __array_interface__:
        def __get__(self):
            inter = {}
            inter['shape'] = self.shape[0], self.shape[1]
            inter['strides'] = self.strides[0], self.strides[1]
            if self.basetype == '8u':
                inter['typestr'] = '|u1'
            else:
                raise NotImplementedError('')
            readonly = True
            data_ptr_int = <intptr_t>self.im
            inter['data'] = (data_ptr_int,readonly)
            return inter

    property size:
        def __get__(self):
            return self.imsiz

    cdef FastImageBase c_roi( self, int left, int bottom, Size size):
        cdef FastImageBase result
        global FASTIMAGEDEBUG

        if FASTIMAGEDEBUG>=2:
            print self,'creating ROI viewer'
        result = self.__new__(type(self)) # new object of my same type
        FastImageBase.__init__(result, size) # run common __init__
        result.strides[0] = self.strides[0]
        result.step = self.step
        if self.basetype == '8u':
            result.im = IMPOS8u(<ipp.Ipp8u*>self.im,self.step,bottom,left)
        elif self.basetype == '32f':
            result.im = IMPOS32f(<ipp.Ipp32f*>self.im,self.step,bottom,left)
        else:
            raise ValueError('unknown basetype: %r'%self.basetype)
        if FASTIMAGEDEBUG>=2:
            print self,'assigning ROI from self (im: %#x)\n    to (%s: 0x%0x) (L:%d,B:%d)'%(<intptr_t>self.im,
                                                          str(result),
                                                          <intptr_t>result.im,
                                                          left,bottom)
        result.source_data = self # keep reference to original image in case it goes out of scope elsewhere
        return result

    def roi( self, int left, int bottom, Size size):
        # python version of C version
        return self.c_roi(left,bottom,size)

    def __getitem__(self,a):
        cdef int i,j
        cdef fiptr valptr

        i,j = a # a must be sequence of ints

        valptr = (self.im+i*self.step)+j*self.strides[1]

        if self.basetype == '8u':
            return (<ipp.Ipp8u*>valptr)[0]
        elif self.basetype == '32f':
            return (<ipp.Ipp32f*>valptr)[0]
        else:
            raise ValueError('unknown basetype: %r'%self.basetype)

##    def __getitem__(self,*args,**kw):
##        print '*args',args
##        print '**kw',kw

cdef class FastImage32f(FastImageBase) # forward declaration
cdef class FastImage8u(FastImageBase):
    """a fast 2D array of 8u"""

    def __cinit__(self,*args,**kw):
        self.strides[1] = 1
        self.basetype = '8u'

    def __init__(self, Size size ):
        global FASTIMAGEDEBUG

        FastImageBase.__init__(self, size)
        if FASTIMAGEDEBUG>=1:
            print self,'requesting memory (size W:%d H:%d)'%(self.imsiz.sz.width,
                                                             self.imsiz.sz.height)
            if FASTIMAGEDEBUG>=3:
                sys.stderr.write('-='*20+'\n')
                traceback.print_stack()
                sys.stderr.write('-='*20+'\n\n')
                sys.stderr.flush()

        self.im=ipp.ippiMalloc_8u_C1( size.sz.width, size.sz.height, &self.step )
        if self.step<size.sz.width:
            raise MemoryError('self.step is %d (width=%d, height=%d)'%(
                self.step, size.sz.width, size.sz.height))
        if self.im==NULL: raise MemoryError("Error allocating memory")
        self.strides[0] = self.step
        if FASTIMAGEDEBUG>=1:
            self.show_mem_and_step()
        self.view = 0

    def set_val(self, int val, Size size):
        CHK_HAVEGIL( ipp.ippiSet_8u_C1R( val, <ipp.Ipp8u*>self.im, self.step, size.sz ))

    def set_val_masked(self, int val, FastImage8u mask, Size size):
        CHK_HAVEGIL( ipp.ippiSet_8u_C1MR( val, <ipp.Ipp8u*>self.im, self.step, size.sz,
                                          <ipp.Ipp8u*>mask.im, mask.step))

    cdef void fast_set_val_masked( self, ipp.Ipp8u val, FastImage8u mask, Size size):
        CHK_HAVEGIL( ipp.ippiSet_8u_C1MR( val, <ipp.Ipp8u*>self.im, self.step, size.sz,
                                        <ipp.Ipp8u*>mask.im, mask.step))

    def get_32f_copy(self,Size size):
        cdef FastImage32f result
        result = FastImage32f(size)
        CHK_HAVEGIL( ipp.ippiConvert_8u32f_C1R(<ipp.Ipp8u*>self.im, self.step,
                                               <ipp.Ipp32f*>result.im, result.step,
                                               size.sz ))
        return result

    def get_32f_copy_put(self,FastImage32f result,Size size):
        CHK_HAVEGIL( ipp.ippiConvert_8u32f_C1R(<ipp.Ipp8u*>self.im, self.step,
                                               <ipp.Ipp32f*>result.im, result.step,
                                               size.sz ))

    cdef void fast_get_32f_copy_put(self,FastImage32f result,Size size):
        CHK_HAVEGIL( ipp.ippiConvert_8u32f_C1R(<ipp.Ipp8u*>self.im, self.step,
                                             <ipp.Ipp32f*>result.im, result.step,
                                             size.sz ))

    def get_8u_copy(self,Size size):
        cdef FastImage8u result
        result = FastImage8u(size)
        CHK_HAVEGIL( ipp.ippiCopy_8u_C1R(<ipp.Ipp8u*>self.im, self.step,
                                         <ipp.Ipp8u*>result.im, result.step,
                                         size.sz ))
        return result

    def get_8u_copy_put(self,FastImage8u result,Size size):
        CHK_HAVEGIL( ipp.ippiCopy_8u_C1R(<ipp.Ipp8u*>self.im, self.step,
                                         <ipp.Ipp8u*>result.im, result.step,
                                         size.sz ))

    def get_absdiff_put(self,FastImage8u other,FastImage8u result,Size size):
        """result = |self - other|"""
        CHK_HAVEGIL( ipp.ippiAbsDiff_8u_C1R(<ipp.Ipp8u*>other.im, other.step,
                                            <ipp.Ipp8u*>self.im, self.step,
                                            <ipp.Ipp8u*>result.im, result.step,
                                            size.sz))

    cdef void fast_get_absdiff_put(self, FastImage8u other, FastImage8u result, Size size):
        CHK_HAVEGIL( ipp.ippiAbsDiff_8u_C1R(<ipp.Ipp8u*>other.im,other.step,
                                          <ipp.Ipp8u*>self.im,self.step,
                                          <ipp.Ipp8u*>result.im,result.step,
                                          size.sz))

    def get_sub_put(self, FastImage8u other, FastImage8u result, Size size):
        """result = self - other"""
        CHK_HAVEGIL( ipp.ippiSub_8u_C1RSfs(<ipp.Ipp8u*>other.im, other.step,
                                           <ipp.Ipp8u*>self.im, self.step,
                                           <ipp.Ipp8u*>result.im, result.step,
                                           size.sz,0))
    cdef void fast_get_sub_put(self, FastImage8u other, FastImage8u result, Size size):
        CHK_HAVEGIL( ipp.ippiSub_8u_C1RSfs(<ipp.Ipp8u*>other.im, other.step,
                                         <ipp.Ipp8u*>self.im, self.step,
                                         <ipp.Ipp8u*>result.im, result.step,
                                         size.sz,0))

    def toself_threshold( self, int compare_value, int new_value, Size size, int op):
        """self = self (op) compare_value ? new_value : self"""
        print 'compare_value',compare_value
        print 'new_value',new_value
        CHK_HAVEGIL( ipp.ippiThreshold_Val_8u_C1IR(<ipp.Ipp8u*>self.im,self.step,
                                                   size.sz, compare_value, new_value,
                                                   <ipp.IppCmpOp>op))

    def get_compare( self, other, Size size, int op ):
        cdef FastImage8u result
        result = FastImage8u(size)
        self.get_compare_put(other, result, size, op)
        return result

    def get_compare_put( self, other, FastImage8u dest, Size size, int op ):
        cdef FastImage8u other8u
        cdef int other_int
        if type(other)==int:
            other_int = other
            CHK_HAVEGIL( ipp.ippiCompareC_8u_C1R( <ipp.Ipp8u*>self.im,self.step,
                                                  other_int,
                                                  <ipp.Ipp8u*>dest.im,dest.step,
                                                  size.sz,<ipp.IppCmpOp>op))
        elif type(other)==FastImage8u:
            other8u = other
            CHK_HAVEGIL( ipp.ippiCompare_8u_C1R( <ipp.Ipp8u*>self.im,self.step,
                                                 <ipp.Ipp8u*>other8u.im,other8u.step,
                                                 <ipp.Ipp8u*>dest.im,dest.step,
                                                 size.sz,<ipp.IppCmpOp>op))
        else:
            raise TypeError("can only compare against ints and FastImage8u types")

    cdef void fast_get_compare_int_put_greater( self, int other_int, FastImage8u dest, Size size):
        CHK_HAVEGIL( ipp.ippiCompareC_8u_C1R( <ipp.Ipp8u*>self.im,self.step,
                                            other_int,
                                            <ipp.Ipp8u*>dest.im,dest.step,
                                            size.sz,
                                            ipp.ippCmpGreater))

    def min_index(self, Size size):
        cdef ipp.IppStatus sts
        cdef int index_x, index_y
        cdef ipp.Ipp8u min_val

        with nogil:
            sts = ipp.ippiMinIndx_8u_C1R(
                <ipp.Ipp8u*>self.im,self.step,
                 size.sz, &min_val, &index_x, &index_y)
        CHK_HAVEGIL(sts)
        return min_val, index_x, index_y

    def max_index(self, Size size):
        cdef ipp.IppStatus sts
        cdef int index_x, index_y
        cdef ipp.Ipp8u max_val

        with nogil:
            sts = ipp.ippiMaxIndx_8u_C1R(
                <ipp.Ipp8u*>self.im, self.step,
                 size.sz, &max_val, &index_x, &index_y)
        CHK_HAVEGIL(sts)
        return max_val, index_x, index_y

    def to_yuv422(self):
        cdef FastImage8u y, u, v

        y = self.get_8u_copy(self.imsiz)
        u = asfastimage(128*numpy.ones_like(y))
        v = u
        return y,u,v

    def dot(self,FastImage8u other,Size size):
        cdef ipp.Ipp64f result

        CHK_HAVEGIL( ipp.ippiDotProd_8u64f_C1R(
            <ipp.Ipp8u*>self.im,self.step,
            <ipp.Ipp8u*>other.im,other.step,
            size.sz, &result ))
        return result

    def sobel_horiz(self, Size size, FastImage8u dest=None):
        cdef fic.FiciSize sz

        sz.width = size.sz.width
        sz.height = size.sz.height
        if dest is None:
            dest = FastImage8u( size )
        else:
            assert dest.size == size
        CHK_FIC_HAVEGIL( fic.ficiFilterSobelHoriz_8u_C1R(<fic.Fic8u*>self.im, self.step, <fic.Fic8u*>dest.im, dest.step, sz ))
        return dest

    def sobel_vert(self, Size size, FastImage8u dest=None):
        cdef fic.FiciSize sz

        sz.width = size.sz.width
        sz.height = size.sz.height
        if dest is None:
            dest = FastImage8u( size )
        else:
            assert dest.size == size
        CHK_FIC_HAVEGIL( fic.ficiFilterSobelVert_8u_C1R(<fic.Fic8u*>self.im, self.step, <fic.Fic8u*>dest.im, dest.step, sz ))
        return dest

cdef class FastImage32f(FastImageBase):

    def __cinit__(self,*args,**kw):
        self.strides[1] = 4
        self.basetype = '32f'

    def __init__(self, Size size ):
        global FASTIMAGEDEBUG

        FastImageBase.__init__(self, size)
        if FASTIMAGEDEBUG>=1:
            print self,'requesting 32f memory (size W:%d H:%d)'%(self.imsiz.sz.width,
                                                             self.imsiz.sz.height)
        self.im=ipp.ippiMalloc_32f_C1( size.sz.width, size.sz.height, &self.step )
        if self.im==NULL: raise MemoryError("Error allocating memory")
        self.strides[0] = self.step
        if FASTIMAGEDEBUG>=1:
            self.show_mem_and_step()
        self.view = 0

    def set_val(self, float val, Size size):
        CHK_HAVEGIL( ipp.ippiSet_32f_C1R( val, <ipp.Ipp32f*>self.im, self.step, size.sz ))

    def toself_add(self, FastImageBase other, Size size):
        """self += other"""
        if isinstance(other,FastImage8u):
            CHK_HAVEGIL( ipp.ippiAdd_8u32f_C1IR( <ipp.Ipp8u*>other.im, other.step,
                                                 <ipp.Ipp32f*>self.im, self.step,
                                                 size.sz))
        elif isinstance(other,FastImage32f):
            CHK_HAVEGIL( ipp.ippiAdd_32f_C1IR( <ipp.Ipp32f*>other.im, other.step,
                                               <ipp.Ipp32f*>self.im, self.step,
                                               size.sz))
        else:
            raise ValueError("type not supported")

    def toself_add_weighted(self, FastImageBase other, Size size, float alpha):
        """self = self*(1-alpha) + alpha*other"""
        if isinstance(other,FastImage8u):
            CHK_HAVEGIL( ipp.ippiAddWeighted_8u32f_C1IR( <ipp.Ipp8u*>other.im, other.step,
                                                         <ipp.Ipp32f*>self.im, self.step,
                                                         size.sz, alpha))
        elif isinstance(other,FastImage32f):
            CHK_HAVEGIL( ipp.ippiAddWeighted_32f_C1IR( <ipp.Ipp32f*>other.im, other.step,
                                                       <ipp.Ipp32f*>self.im, self.step,
                                                       size.sz, alpha))
        else:
            raise ValueError("type not supported")

    cdef void fast_toself_add_weighted_8u( self, FastImage8u other, Size size, float alpha):
        CHK_HAVEGIL( ipp.ippiAddWeighted_8u32f_C1IR( <ipp.Ipp8u*>other.im, other.step,
                                                   <ipp.Ipp32f*>self.im, self.step,
                                                   size.sz, alpha))

    cdef void fast_toself_add_weighted_32f(self, FastImage32f other, Size size, float alpha):
        CHK_HAVEGIL( ipp.ippiAddWeighted_32f_C1IR( <ipp.Ipp32f*>other.im, other.step,
                                                   <ipp.Ipp32f*>self.im, self.step,
                                                   size.sz, alpha))


    def toself_add_square(self, FastImage8u other, Size size):
        """self += other**2"""
        CHK_HAVEGIL( ipp.ippiAddSquare_8u32f_C1IR( <ipp.Ipp8u*>other.im, other.step,
                                                   <ipp.Ipp32f*>self.im, self.step,
                                                     size.sz))
    def get_square_put(self, FastImage32f result, Size size):
        """result = self**2"""
        CHK_HAVEGIL( ipp.ippiSqr_32f_C1R( <ipp.Ipp32f*>self.im, self.step,
                                          <ipp.Ipp32f*>result.im, result.step,
                                          size.sz))

    cdef void fast_get_square_put(self, FastImage32f result, Size size):
        CHK_HAVEGIL( ipp.ippiSqr_32f_C1R( <ipp.Ipp32f*>self.im, self.step,
                                        <ipp.Ipp32f*>result.im, result.step,
                                        size.sz))

    def get_square(self, Size size):
        """return self**2"""
        cdef FastImage32f result
        result = FastImage32f( size )
        CHK_HAVEGIL( ipp.ippiSqr_32f_C1R( <ipp.Ipp32f*>self.im, self.step,
                                          <ipp.Ipp32f*>result.im, result.step,
                                          size.sz))
        return result

    def toself_square(self,Size size):
        """self = self**2"""
        CHK_HAVEGIL( ipp.ippiSqr_32f_C1IR( <ipp.Ipp32f*>self.im, self.step,
                                          size.sz))
    cdef void fast_toself_square(self,Size size):
        CHK_HAVEGIL( ipp.ippiSqr_32f_C1IR( <ipp.Ipp32f*>self.im, self.step,
                                         size.sz))
    def toself_sqrt(self,Size size):
        """self = sqrt(self)"""
        CHK_HAVEGIL( ipp.ippiSqrt_32f_C1IR( <ipp.Ipp32f*>self.im, self.step,
                                            size.sz))

    def get_subtracted(self,FastImage32f other,Size size):
        """result = self - other"""
        cdef FastImage32f result
        result = FastImage32f( size )
        CHK_HAVEGIL( ipp.ippiSub_32f_C1R(<ipp.Ipp32f*>other.im, other.step,
                                          <ipp.Ipp32f*>self.im, self.step,
                                          <ipp.Ipp32f*>result.im, result.step,
                                          size.sz))
        return result

    def get_subtracted_put(self,FastImage32f other,FastImage32f result,Size size):
        """result = self - other"""
        CHK_HAVEGIL( ipp.ippiSub_32f_C1R(<ipp.Ipp32f*>other.im, other.step,
                                          <ipp.Ipp32f*>self.im, self.step,
                                          <ipp.Ipp32f*>result.im, result.step,
                                          size.sz))

    cdef void fast_get_subtracted_put(self,FastImage32f other,FastImage32f result,Size size):
        """result = self - other"""
        CHK_HAVEGIL( ipp.ippiSub_32f_C1R(<ipp.Ipp32f*>other.im, other.step,
                                          <ipp.Ipp32f*>self.im, self.step,
                                          <ipp.Ipp32f*>result.im, result.step,
                                          size.sz))

    def toself_subtract(self,FastImage32f other,Size size):
        """self = self - other"""
        CHK_HAVEGIL( ipp.ippiSub_32f_C1IR(<ipp.Ipp32f*>other.im, other.step,
                                          <ipp.Ipp32f*>self.im, self.step,
                                          size.sz))

    def get_8u_copy(self,Size size):
        """other = self"""
        cdef FastImage8u other
        other = FastImage8u(size)
        CHK_HAVEGIL( ipp.ippiConvert_32f8u_C1R(
            <ipp.Ipp32f*>self.im,self.step,
            <ipp.Ipp8u*>other.im,other.step,
            size.sz, ipp.ippRndNear ))
        return other

    def get_8u_copy_put(self,FastImage8u other,Size size):
        """other = self"""
        CHK_HAVEGIL( ipp.ippiConvert_32f8u_C1R(
            <ipp.Ipp32f*>self.im,self.step,
            <ipp.Ipp8u*>other.im,other.step,
            size.sz, ipp.ippRndNear ))

    cdef void fast_get_8u_copy_put(self,FastImage8u other,Size size):
        CHK_HAVEGIL( ipp.ippiConvert_32f8u_C1R(
            <ipp.Ipp32f*>self.im,self.step,
            <ipp.Ipp8u*>other.im,other.step,
            size.sz, ipp.ippRndNear ))

    def toself_multiply(self, float val, Size size):
        "self = self * C"
        CHK_HAVEGIL( ipp.ippiMulC_32f_C1IR(val, <ipp.Ipp32f*>self.im, self.step, size.sz))

    cdef void fast_toself_multiply(self, float val, Size size):
        CHK_HAVEGIL( ipp.ippiMulC_32f_C1IR(val, <ipp.Ipp32f*>self.im, self.step, size.sz))

    def get_multiply_put(self, float val, FastImage32f other, Size size):
        "other = self * C"
        CHK_HAVEGIL( ipp.ippiMulC_32f_C1R(<ipp.Ipp32f*>self.im, self.step,  val,
                                          <ipp.Ipp32f*>other.im,other.step, size.sz))

    def pow(self,y):
        cdef FastImage32f xself
        xself = copy(self)
        if y == 2:
            xself.toself_square(xself.imsiz)
        elif y==0.5:
            xself.toself_sqrt(xself.imsiz)
        else:
            raise ValueError("only 2 and 0.5 powers supported")
        return xself

    def max_index(self, Size size):
        cdef ipp.IppStatus sts
        cdef int index_x, index_y
        cdef ipp.Ipp32f max_val

        with nogil:
            sts = ipp.ippiMaxIndx_32f_C1R(
                <ipp.Ipp32f*>self.im, self.step,
                 size.sz, &max_val, &index_x, &index_y)
        CHK_HAVEGIL(sts)
        return max_val, index_x, index_y

    def dot(self,FastImage32f other,Size size):
        cdef ipp.Ipp64f result
        cdef ipp.IppHintAlgorithm algo = ipp.ippAlgHintAccurate

        CHK_HAVEGIL( ipp.ippiDotProd_32f64f_C1R(
            <ipp.Ipp32f*>self.im,self.step,
            <ipp.Ipp32f*>other.im,other.step,
            size.sz, &result, algo ))
        return result

    cdef FastImage32f create_equal_shape_empty(self, Size size):
        cdef FastImage32f dest
        dest = FastImage32f( size )
        if dest.step != self.step:
            shape = ( size.sz.height, self.step/4 )
            dtype = numpy.float32
            tmp = numpy.empty( shape, dtype=dtype)
            tmp = tmp[:,:size.sz.width]
            dest = asfastimage(tmp)
        return dest

    def sobel_horiz(self, Size size, FastImage32f dest=None):
        cdef fic.FiciSize sz
        cdef int created_dest

        created_dest = 0

        sz.width = size.sz.width
        sz.height = size.sz.height
        if dest is None:
            dest = self.create_equal_shape_empty(size)
        else:
            assert dest.size == size
        CHK_FIC_HAVEGIL( fic.ficiFilterSobelHoriz_32f_C1R(<fic.Fic32f*>self.im, self.step, <fic.Fic32f*>dest.im, dest.step, sz ))
        return dest

    def sobel_vert(self, Size size, FastImage32f dest=None):
        cdef fic.FiciSize sz

        sz.width = size.sz.width
        sz.height = size.sz.height
        if dest is None:
            dest = self.create_equal_shape_empty(size)
        else:
            assert dest.size == size
        CHK_FIC_HAVEGIL( fic.ficiFilterSobelVert_32f_C1R(<fic.Fic32f*>self.im, self.step, <fic.Fic32f*>dest.im, dest.step, sz ))
        return dest

def asfastimage( object arr ):
    """return a FastImage view of an array"""
    cdef PyArrayInterface* inter
    cdef FastImageBase result

    global FASTIMAGEDEBUG

    attr = arr.__array_struct__
    if not cpython.cobject.PyCObject_Check(attr):
        raise ValueError("invalid __array_struct__")

    inter = <PyArrayInterface*>cpython.cobject.PyCObject_AsVoidPtr(attr)
    if inter.two != 2:
        raise ValueError("invalid __array_struct__")

    if (inter.flags & ARR_HAS_DESCR) == (ARR_HAS_DESCR):
        raise ValueError("cannot handle arrays with descr")

    # TODO: don't really know what these flags all mean, figure out if
    # this is OK:
    if (inter.flags & (ALIGNED | WRITEABLE)) != (ALIGNED | WRITEABLE):
        raise ValueError("cannot handle misaligned or not writeable arrays.")

    if inter.nd != 2:
        raise ValueError("only 2D arrays may be viewed as a FastImage")

    if FASTIMAGEDEBUG>=2:
        print 'asfastimage() calling __new__'
    if inter.typekind == CHAR_u and inter.itemsize==1:
        result = FastImage8u.__new__(FastImage8u)
##    elif inter.typekind == "b"[0] and inter.itemsize==1: # "bool" true or false
##        result = FastImage8u.__new__(FastImage8u)
    elif inter.typekind == CHAR_f and inter.itemsize==4:
        result = FastImage32f.__new__(FastImage32f)
    else:
        raise ValueError('typekind "%s", itemsize %d not supported'%(chr(inter.typekind),inter.itemsize))
    if (inter.shape[0] > INT_MAX) or (inter.shape[1] > INT_MAX) or (inter.strides[0] > INT_MAX):
        raise ValueError("cannot handle such large data")
    FastImageBase.__init__(result, Size(inter.shape[1],inter.shape[0])) # run common __init__
    result.strides[0] = inter.strides[0]
    result.step = inter.strides[0]
    result.im = inter.data

    result.source_data = arr # keep reference to original image in case it goes out of scope elsewhere

    if FASTIMAGEDEBUG>=2:
        print '  result',result
        print '    result.view',result.view

    return result

def copy( object arr ):
    """return a FastImage copy of an array"""
    cdef PyArrayInterface* inter
    cdef FastImageBase result
    cdef int i

    attr = arr.__array_struct__
    if not cpython.cobject.PyCObject_Check(attr):
        raise ValueError("invalid __array_struct__")

    inter = <PyArrayInterface*>cpython.cobject.PyCObject_AsVoidPtr(attr)
    if inter.two != 2:
        raise ValueError("invalid __array_struct__")

    if (inter.flags & ARR_HAS_DESCR) == (ARR_HAS_DESCR):
        raise ValueError("cannot handle arrays with descr")

    # TODO: don't really know what these flags all mean, figure out if
    # this is OK:
    if (inter.flags & (ALIGNED)) != (ALIGNED):
        raise ValueError("cannot handle misaligned arrays.")

    if inter.nd != 2:
        raise ValueError("only 2D arrays may be copied to a FastImage")

    if (inter.shape[0] > INT_MAX) or (inter.shape[1] > INT_MAX) or (inter.strides[0] > INT_MAX):
        raise ValueError("cannot handle such large data")

    if inter.typekind == CHAR_u and inter.itemsize==1:
        result = FastImage8u(Size(inter.shape[1],inter.shape[0])) # allocate memory
    elif inter.typekind == CHAR_f and inter.itemsize==4:
        result = FastImage32f(Size(inter.shape[1],inter.shape[0])) # allocate memory
    else:
        raise ValueError('typekind "%s", itemsize %d not supported'%(chr(inter.typekind),inter.itemsize))

    # TODO: make sure that we can rely on blocks like this:
    for i from 0 <= i < inter.shape[0]:
        libc.string.memcpy( result.im + i*result.step,
                            inter.data + i*inter.strides[0],
                            inter.shape[1]*result.strides[1] )

    return result
