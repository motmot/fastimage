#emacs, this is -*-Python-*- mode

# indexing starts from left, bottom

cimport c_lib
import traceback, sys
import numpy

cdef int FASTIMAGEDEBUG
FASTIMAGEDEBUG = 0

# for computing histograms
cdef int n_hist_levels
n_hist_levels = 256
cdef fw.Fw32s hist_levels[257]
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

####################################

cdef ensure_framewave_bug_SF2541341_fixed():
    cdef fw.Fw8u* im
    cdef int step, width, height

    # This is essentially the same test as SF #2541341
    for width from 2<= width < 3: # original test went to 10
        for height from 2 <= height < 3: # original test went to 10
            im = fw.fwiMalloc_8u_C1( width, height, &step)
            if im==NULL: raise MemoryError("Error allocating memory")
            if step<width:
                raise RuntimeError('Your AMD Framewave installation has a '
                                   'serious bug. For %dx%d image, the '
                                   'allocated step %d is less than the width. '
                                   'This bug should is fixed in Framewave 1.4 '
                                   'or in svn r469 or higher.'%(
                    width,height,step))
            fw.fwiFree(im)

cdef extern from "FastImage_macros.h":
    # for PyArrayInterface
    int CONTIGUOUS
    int FORTRAN
    int ALIGNED
    int NOTSWAPPED
    int WRITEABLE
    int ARR_HAS_DESCR

    # for FW
    fw.Fw8u*  IMPOS8u(  fw.Fw8u*  im, int step, int bottom, int left)
    fw.Fw32f* IMPOS32f( fw.Fw32f* im, int step, int bottom, int left)
    void CHK_NOGIL( fw.FwStatus errval )

    char* fwGetStatusString( fw.FwStatus StsCode )

    cdef void InitStaticIfNecessary()

    ctypedef struct fw_version_struct_t:
        int major
        int minor
        int build

    cdef fw_version_struct_t GetFWVersion()
#    cdef char* GetFWArch()
    cdef int IsFWStatic()

InitStaticIfNecessary()
ensure_framewave_bug_SF2541341_fixed()

def get_FW_version():
    cdef fw_version_struct_t val
    val = GetFWVersion()
    return val.major, val.minor, val.build

## def get_FW_arch():
##     cdef char* arch_str
##     arch_str = GetFWArch()
##     return arch_str

def get_FW_static():
    return IsFWStatic()

class FwError(Exception):
    def __init__(self, int errval):
        cdef char* cmsg
        cmsg = fwGetStatusString(<fw.FwStatus>errval)
        #Exception.__init__(self,"Error %d: %s"%(errval,cmsg))
        Exception.__init__(self,cmsg)

class FicError(Exception):
    pass

cdef void CHK_HAVEGIL( fw.FwStatus errval ) except *:
    if (errval!=0):
        raise FwError(errval)

cdef void CHK_FIC_HAVEGIL( fic.FicStatus errval ) except *:
    if (errval!=0):
        raise FicError('error %d'%errval)

ctypedef struct PyArrayInterface:
    int two                       # contains the integer 2 as a sanity check
    int nd                        # number of dimensions
    char typekind                 # kind in array --- character code of typestr
    int itemsize                  # size of each element
    int flags                     # flags indicating how the data should be interpreted
    c_python.Py_intptr_t *shape   # A length-nd array of shape information
    c_python.Py_intptr_t *strides # A length-nd array of stride information
    void *data                    # A pointer to the first element of the array

cdef void free_array_struct( void* ptr, void *arr ):
    arrpy = <object>arr
    c_python.Py_DECREF( arrpy )
    c_lib.free(ptr)

# comparision operators
CmpLess = fw.fwCmpLess
CmpLessEq = fw.fwCmpLessEq
CmpEq = fw.fwCmpEq
CmpGreaterEq = fw.fwCmpGreaterEq
CmpGreater = fw.fwCmpGreater

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
            fw.fwiFree(self.im)

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
                    line.append((<fw.Fw8u*>valptr)[0])
                elif self.basetype == '32f':
                    line.append((<fw.Fw32f*>valptr)[0])
            line = ' '.join(map(str,line))
            lines.append(line)
        lines = '\n'.join(lines)
        return lines

    def dump_to_file(self,fobj):
        cdef int i
        cdef int nbytes
        cdef int nbytes_tot
        cdef int bytes_per_pixel
        cdef fiptr rowptr
        cdef fiptr valptr
        cdef c_lib.FILE* fd
        nbytes_tot = 0
        bytes_per_pixel = self.strides[1]
        if not c_python.PyFile_Check(fobj):
            raise ValueError('need file object')
        fd = c_python.PyFile_AsFile(fobj)
        c_python.Py_BEGIN_ALLOW_THREADS
        for i from 0 <= i < self.imsiz.sz.height:
            rowptr = self.im+i*self.step
            nbytes = c_lib.fwrite( rowptr, 1, self.imsiz.sz.width*bytes_per_pixel, fd )
            nbytes_tot = nbytes_tot+nbytes
        c_python.Py_END_ALLOW_THREADS
        return nbytes_tot

    property __array_struct__:
        def __get__(self):
            cdef PyArrayInterface* inter

            inter = <PyArrayInterface*>c_lib.malloc( sizeof( PyArrayInterface ) )
            inter.two = 2
            inter.nd = 2
            if self.basetype == '8u':
                inter.typekind = 'u'[0] # unsigned int
            elif self.basetype == '32f':
                inter.typekind = 'f'[0] # float
            inter.itemsize = self.strides[1]
            inter.flags = NOTSWAPPED | ALIGNED | WRITEABLE
            inter.strides = self.strides
            inter.shape = self.shape
            inter.data = self.im
            c_python.Py_INCREF(self)
            obj = c_python.PyCObject_FromVoidPtrAndDesc( <void*>inter, <void*>self, free_array_struct)
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
            result.im = IMPOS8u(<fw.Fw8u*>self.im,self.step,bottom,left)
        elif self.basetype == '32f':
            result.im = IMPOS32f(<fw.Fw32f*>self.im,self.step,bottom,left)
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
        """get element at i,j where i is the row and j is the col"""
        cdef int i,j
        cdef fiptr valptr

        i,j = a # a must be sequence of ints

        valptr = (self.im+i*self.step)+j*self.strides[1]

        if self.basetype == '8u':
            return (<fw.Fw8u*>valptr)[0]
        elif self.basetype == '32f':
            return (<fw.Fw32f*>valptr)[0]

    def _test_read_all(self):
        cdef int i,j
        cdef fw.FwiSize sz
        cdef fiptr valptr
        cdef fw.Fw8u val8u
        cdef fw.Fw32f val32f
        cdef float cum

        sz = self.imsiz.sz
        cum = 0
        for i from 0<= i < sz.height:
            for j from 0<= j < sz.width:
                valptr = (self.im+i*self.step)+j*self.strides[1]

                if self.basetype == '8u':
                    val8u = (<fw.Fw8u*>valptr)[0]
                    cum = cum + val8u
                elif self.basetype == '32f':
                    val32f = (<fw.Fw32f*>valptr)[0]
                    cum = cum + val32f

    def _test_write_all(self,float val):
        cdef int i,j
        cdef fw.FwiSize sz
        cdef fiptr valptr
        cdef fw.Fw8u val8u
        cdef fw.Fw32f val32f

        val8u = <fw.Fw8u>val # truncate
        val32f = val

        sz = self.imsiz.sz
        for i from 0<= i < sz.height:
            for j from 0<= j < sz.width:
                valptr = (self.im+i*self.step)+j*self.strides[1]

                if self.basetype == '8u':
                    (<fw.Fw8u*>valptr)[0] = val8u
                elif self.basetype == '32f':
                    (<fw.Fw32f*>valptr)[0] = val32f

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

        self.im=fw.fwiMalloc_8u_C1( size.sz.width, size.sz.height, &self.step )
        if self.step<size.sz.width:
            raise MemoryError('self.step is %d (width=%d, height=%d)'%(
                self.step, size.sz.width, size.sz.height))
        if self.im==NULL: raise MemoryError("Error allocating memory")
        self.strides[0] = self.step
        if FASTIMAGEDEBUG>=1:
            self.show_mem_and_step()
        self.view = 0

    def histogram(self):
        cdef PyArrayInterface* inter
        cdef fw.FwStatus sts

        hist = numpy.empty((256,),dtype=numpy.int32)
        cobj = hist.__array_struct__

        if not c_python.PyCObject_Check(cobj):
            raise TypeError("expected CObject")
        inter = <PyArrayInterface*>c_python.PyCObject_AsVoidPtr(cobj)
        assert inter.two==2

        raise NotImplementedError('xxx')

    def set_val(self, int val, Size size):
        CHK_HAVEGIL( fw.fwiSet_8u_C1R( val, <fw.Fw8u*>self.im, self.step, size.sz ))

    def set_val_masked(self, int val, FastImage8u mask, Size size):
        CHK_HAVEGIL( fw.fwiSet_8u_C1MR( val, <fw.Fw8u*>self.im, self.step, size.sz,
                                          <fw.Fw8u*>mask.im, mask.step))

    cdef void fast_set_val_masked( self, fw.Fw8u val, FastImage8u mask, Size size):
        CHK_HAVEGIL( fw.fwiSet_8u_C1MR( val, <fw.Fw8u*>self.im, self.step, size.sz,
                                        <fw.Fw8u*>mask.im, mask.step))

    def get_32f_copy(self,Size size):
        cdef FastImage32f result
        result = FastImage32f(size)
        CHK_HAVEGIL( fw.fwiConvert_8u32f_C1R(<fw.Fw8u*>self.im, self.step,
                                               <fw.Fw32f*>result.im, result.step,
                                               size.sz ))
        return result

    def get_32f_copy_put(self,FastImage32f result,Size size):
        CHK_HAVEGIL( fw.fwiConvert_8u32f_C1R(<fw.Fw8u*>self.im, self.step,
                                               <fw.Fw32f*>result.im, result.step,
                                               size.sz ))

    cdef void fast_get_32f_copy_put(self,FastImage32f result,Size size):
        CHK_HAVEGIL( fw.fwiConvert_8u32f_C1R(<fw.Fw8u*>self.im, self.step,
                                             <fw.Fw32f*>result.im, result.step,
                                             size.sz ))

    def get_8u_copy(self,Size size):
        cdef FastImage8u result
        result = FastImage8u(size)
        CHK_HAVEGIL( fw.fwiCopy_8u_C1R(<fw.Fw8u*>self.im, self.step,
                                         <fw.Fw8u*>result.im, result.step,
                                         size.sz ))
        return result

    def get_8u_copy_put(self,FastImage8u result,Size size):
        CHK_HAVEGIL( fw.fwiCopy_8u_C1R(<fw.Fw8u*>self.im, self.step,
                                         <fw.Fw8u*>result.im, result.step,
                                         size.sz ))

    def get_crosscorr_same_norm_put_32f( self, Size source_size,
                                                FastImage8u other, Size other_size,
                                                FastImage32f result, int scale_factor ):
        """result = CrossCorr(self,other)

        result has same dimensions as self
        result is normalized"""
        cdef fw.FwStatus sts

        raise NotImplementedError('xxx')

    def get_crosscorr_same_norm_32f( self, Size source_size,
                                     FastImage8u other, Size other_size,
                                     int scale_factor ):
        """result = CrossCorr(self,other)

        result has same dimensions as self
        result is normalized"""
        raise NotImplementedError('xxx')

    def get_crosscorr_same_norm_scaled_put_8u( self, Size source_size,
                                               FastImage8u other, Size other_size,
                                               FastImage8u result, int scale_factor ):
        """result = CrossCorr(self,other)

        result has same dimensions as self
        result is normalized"""
        raise NotImplementedError('xxx')

    def get_crosscorr_same_norm_scaled_8u( self, Size source_size,
                                           FastImage8u other, Size other_size,
                                           int scale_factor ):
        """result = CrossCorr(self,other)

        result has same dimensions as self
        result is normalized"""
        cdef FastImage8u result
        result = FastImage8u( source_size )
        self.get_crosscorr_same_norm_scaled_put_8u( source_size, other, other_size,
                                                    result, scale_factor )
        return result

    def get_absdiff_put(self,FastImage8u other,FastImage8u result,Size size):
        """result = |self - other|"""
        CHK_HAVEGIL( fw.fwiAbsDiff_8u_C1R(<fw.Fw8u*>other.im, other.step,
                                            <fw.Fw8u*>self.im, self.step,
                                            <fw.Fw8u*>result.im, result.step,
                                            size.sz))

    cdef void fast_get_absdiff_put(self, FastImage8u other, FastImage8u result, Size size):
        CHK_HAVEGIL( fw.fwiAbsDiff_8u_C1R(<fw.Fw8u*>other.im,other.step,
                                          <fw.Fw8u*>self.im,self.step,
                                          <fw.Fw8u*>result.im,result.step,
                                          size.sz))

    def get_sub_put(self, FastImage8u other, FastImage8u result, Size size):
        """result = self - other"""
        CHK_HAVEGIL( fw.fwiSub_8u_C1RSfs(<fw.Fw8u*>other.im, other.step,
                                           <fw.Fw8u*>self.im, self.step,
                                           <fw.Fw8u*>result.im, result.step,
                                           size.sz,0))
    cdef void fast_get_sub_put(self, FastImage8u other, FastImage8u result, Size size):
        CHK_HAVEGIL( fw.fwiSub_8u_C1RSfs(<fw.Fw8u*>other.im, other.step,
                                         <fw.Fw8u*>self.im, self.step,
                                         <fw.Fw8u*>result.im, result.step,
                                         size.sz,0))

    def toself_threshold( self, int compare_value, int new_value, Size size, int op):
        """self = self (op) compare_value ? new_value : self"""
        print 'compare_value',compare_value
        print 'new_value',new_value
        CHK_HAVEGIL( fw.fwiThreshold_Val_8u_C1IR(<fw.Fw8u*>self.im,self.step,
                                                   size.sz, compare_value, new_value,
                                                   <fw.FwCmpOp>op))

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
            CHK_HAVEGIL( fw.fwiCompareC_8u_C1R( <fw.Fw8u*>self.im,self.step,
                                                  other_int,
                                                  <fw.Fw8u*>dest.im,dest.step,
                                                  size.sz,<fw.FwCmpOp>op))
        elif type(other)==FastImage8u:
            other8u = other
            CHK_HAVEGIL( fw.fwiCompare_8u_C1R( <fw.Fw8u*>self.im,self.step,
                                                 <fw.Fw8u*>other8u.im,other8u.step,
                                                 <fw.Fw8u*>dest.im,dest.step,
                                                 size.sz,<fw.FwCmpOp>op))
        else:
            raise TypeError("can only compare against ints and FastImage8u types")

    cdef void fast_get_compare_int_put_greater( self, int other_int, FastImage8u dest, Size size):
        CHK_HAVEGIL( fw.fwiCompareC_8u_C1R( <fw.Fw8u*>self.im,self.step,
                                            other_int,
                                            <fw.Fw8u*>dest.im,dest.step,
                                            size.sz,
                                            fw.fwCmpGreater))

    def __imod__(self, object other):
        cdef FastImage32f other32f
        cdef convert_to_8u convert_to_8u_op
        if type(other) == convert_to_8u:
            convert_to_8u_op = other
            other32f = convert_to_8u_op.orig32f
            assert self.imsiz == other32f.imsiz
            other32f.get_8u_copy_put(self,self.imsiz)
        else:
            raise TypeError('cannot mod type in-place')
        return self

    def min_index(self, Size size):
        cdef fic.FicStatus sts
        cdef int index_x, index_y
        cdef fic.Fic8u min_val
        cdef fic.FiciSize sz

        sz.width = size.sz.width
        sz.height = size.sz.height
        c_python.Py_BEGIN_ALLOW_THREADS # release GIL
        sts = fic.ficiMinIndx_8u_C1R(
            <fic.Fic8u*>self.im,self.step,
            sz, &min_val, &index_x, &index_y)
        c_python.Py_END_ALLOW_THREADS # acquire GIL
        CHK_FIC_HAVEGIL(sts)
        return min_val, index_x, index_y

    def max_index(self, Size size):
        cdef fic.FicStatus sts
        cdef int index_x, index_y
        cdef fic.Fic8u max_val
        cdef fic.FiciSize sz

        sz.width = size.sz.width
        sz.height = size.sz.height
        c_python.Py_BEGIN_ALLOW_THREADS # release GIL
        sts = fic.ficiMaxIndx_8u_C1R(
            <fic.Fic8u*>self.im,self.step,
            sz, &max_val, &index_x, &index_y)
        c_python.Py_END_ALLOW_THREADS # acquire GIL
        CHK_FIC_HAVEGIL(sts)
        return max_val, index_x, index_y

    def to_yuv422(self):
        cdef FastImage8u y, u, v

        y = self.get_8u_copy(self.imsiz)
        u = asfastimage(128*numpy.ones_like(y))
        v = u
        return y,u,v

    def dot(self,FastImage8u other,Size size):
        cdef fic.Fic64f result
        cdef fic.FiciSize sz

        sz.width = size.sz.width
        sz.height = size.sz.height
        CHK_FIC_HAVEGIL( fic.ficiDotProd_8u64f_C1R(
            <fic.Fic8u*>self.im,self.step,
            <fic.Fic8u*>other.im,other.step,
            sz, &result ))
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

    def dilate3x3(self,Size size,FastImage8u dest=None):
        if dest is None:
            dest = FastImage8u( size )
        else:
            assert dest.size == size
        CHK_HAVEGIL( fw.fwiDilate3x3_8u_C1R(<fw.Fw8u*>self.im, self.step, <fw.Fw8u*>dest.im, dest.step, size.sz ))
        return dest

#    def dilate3x3_inplace(self,Size size,n_iter=1):
#        for i in range(n_iter):
#            CHK_HAVEGIL( fw.fwiDilate3x3_8u_C1IR(<fw.Fw8u*>self.im, self.step, size.sz ))

    def gauss3x3(self,Size size):
        cdef FastImage8u out
        out = FastImage8u(size)
        CHK_HAVEGIL( fw.fwiFilterGauss_8u_C1R(<fw.Fw8u*>self.im, self.step,
                                              <fw.Fw8u*>out.im, out.step,
                                              size.sz, fw.fwMskSize3x3 ))
        return out

    def gauss5x5(self,Size size):
        cdef FastImage8u out
        out = FastImage8u(size)
        CHK_HAVEGIL( fw.fwiFilterGauss_8u_C1R(<fw.Fw8u*>self.im, self.step,
                                              <fw.Fw8u*>out.im, out.step,
                                              size.sz, fw.fwMskSize5x5 ))
        return out

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
        self.im=fw.fwiMalloc_32f_C1( size.sz.width, size.sz.height, &self.step )
        if self.im==NULL: raise MemoryError("Error allocating memory")
        self.strides[0] = self.step
        if FASTIMAGEDEBUG>=1:
            self.show_mem_and_step()
        self.view = 0

    def set_val(self, float val, Size size):
        CHK_HAVEGIL( fw.fwiSet_32f_C1R( val, <fw.Fw32f*>self.im, self.step, size.sz ))

    def toself_add(self, FastImageBase other, Size size):
        """self += other"""
        if isinstance(other,FastImage8u):
            CHK_HAVEGIL( fw.fwiAdd_8u32f_C1IR( <fw.Fw8u*>other.im, other.step,
                                                 <fw.Fw32f*>self.im, self.step,
                                                 size.sz))
        elif isinstance(other,FastImage32f):
            CHK_HAVEGIL( fw.fwiAdd_32f_C1IR( <fw.Fw32f*>other.im, other.step,
                                               <fw.Fw32f*>self.im, self.step,
                                               size.sz))
        else:
            raise ValueError("type not supported")

    def toself_add_weighted(self, FastImageBase other, Size size, float alpha):
        """self = self*(1-alpha) + alpha*other"""
        if isinstance(other,FastImage8u):
            CHK_HAVEGIL( fw.fwiAddWeighted_8u32f_C1IR( <fw.Fw8u*>other.im, other.step,
                                                         <fw.Fw32f*>self.im, self.step,
                                                         size.sz, alpha))
        elif isinstance(other,FastImage32f):
            CHK_HAVEGIL( fw.fwiAddWeighted_32f_C1IR( <fw.Fw32f*>other.im, other.step,
                                                       <fw.Fw32f*>self.im, self.step,
                                                       size.sz, alpha))
        else:
            raise ValueError("type not supported")

    cdef void fast_toself_add_weighted_8u( self, FastImage8u other, Size size, float alpha):
        CHK_HAVEGIL( fw.fwiAddWeighted_8u32f_C1IR( <fw.Fw8u*>other.im, other.step,
                                                   <fw.Fw32f*>self.im, self.step,
                                                   size.sz, alpha))

    cdef void fast_toself_add_weighted_32f(self, FastImage32f other, Size size, float alpha):
        CHK_HAVEGIL( fw.fwiAddWeighted_32f_C1IR( <fw.Fw32f*>other.im, other.step,
                                                   <fw.Fw32f*>self.im, self.step,
                                                   size.sz, alpha))


    def toself_add_square(self, FastImage8u other, Size size):
        """self += other**2"""
        CHK_HAVEGIL( fw.fwiAddSquare_8u32f_C1IR( <fw.Fw8u*>other.im, other.step,
                                                   <fw.Fw32f*>self.im, self.step,
                                                     size.sz))
    def get_square_put(self, FastImage32f result, Size size):
        """result = self**2"""
        CHK_HAVEGIL( fw.fwiSqr_32f_C1R( <fw.Fw32f*>self.im, self.step,
                                          <fw.Fw32f*>result.im, result.step,
                                          size.sz))

    cdef void fast_get_square_put(self, FastImage32f result, Size size):
        CHK_HAVEGIL( fw.fwiSqr_32f_C1R( <fw.Fw32f*>self.im, self.step,
                                        <fw.Fw32f*>result.im, result.step,
                                        size.sz))

    def get_square(self, Size size):
        """return self**2"""
        cdef FastImage32f result
        result = FastImage32f( size )
        CHK_HAVEGIL( fw.fwiSqr_32f_C1R( <fw.Fw32f*>self.im, self.step,
                                          <fw.Fw32f*>result.im, result.step,
                                          size.sz))
        return result

    def toself_square(self,Size size):
        """self = self**2"""
        CHK_HAVEGIL( fw.fwiSqr_32f_C1IR( <fw.Fw32f*>self.im, self.step,
                                          size.sz))
    cdef void fast_toself_square(self,Size size):
        CHK_HAVEGIL( fw.fwiSqr_32f_C1IR( <fw.Fw32f*>self.im, self.step,
                                         size.sz))
    def toself_sqrt(self,Size size):
        """self = sqrt(self)"""
        CHK_HAVEGIL( fw.fwiSqrt_32f_C1IR( <fw.Fw32f*>self.im, self.step,
                                            size.sz))

    def get_subtracted(self,FastImage32f other,Size size):
        """result = self - other"""
        cdef FastImage32f result
        result = FastImage32f( size )
        CHK_HAVEGIL( fw.fwiSub_32f_C1R(<fw.Fw32f*>other.im, other.step,
                                          <fw.Fw32f*>self.im, self.step,
                                          <fw.Fw32f*>result.im, result.step,
                                          size.sz))
        return result

    def get_subtracted_put(self,FastImage32f other,FastImage32f result,Size size):
        """result = self - other"""
        CHK_HAVEGIL( fw.fwiSub_32f_C1R(<fw.Fw32f*>other.im, other.step,
                                          <fw.Fw32f*>self.im, self.step,
                                          <fw.Fw32f*>result.im, result.step,
                                          size.sz))

    cdef void fast_get_subtracted_put(self,FastImage32f other,FastImage32f result,Size size):
        """result = self - other"""
        CHK_HAVEGIL( fw.fwiSub_32f_C1R(<fw.Fw32f*>other.im, other.step,
                                          <fw.Fw32f*>self.im, self.step,
                                          <fw.Fw32f*>result.im, result.step,
                                          size.sz))

    def toself_subtract(self,FastImage32f other,Size size):
        """self = self - other"""
        CHK_HAVEGIL( fw.fwiSub_32f_C1IR(<fw.Fw32f*>other.im, other.step,
                                          <fw.Fw32f*>self.im, self.step,
                                          size.sz))

    def get_8u_copy(self,Size size):
        """other = self"""
        cdef FastImage8u other
        other = FastImage8u(size)
        CHK_HAVEGIL( fw.fwiConvert_32f8u_C1R(
            <fw.Fw32f*>self.im,self.step,
            <fw.Fw8u*>other.im,other.step,
            size.sz))#, fw.fwRndNear ))
        return other

    def get_8u_copy_put(self,FastImage8u other,Size size):
        """other = self"""
        CHK_HAVEGIL( fw.fwiConvert_32f8u_C1R(
            <fw.Fw32f*>self.im,self.step,
            <fw.Fw8u*>other.im,other.step,
            size.sz))#, fw.fwRndNear ))

    cdef void fast_get_8u_copy_put(self,FastImage8u other,Size size):
        CHK_HAVEGIL( fw.fwiConvert_32f8u_C1R(
            <fw.Fw32f*>self.im,self.step,
            <fw.Fw8u*>other.im,other.step,
            size.sz))#, fw.fwRndNear ))

    def toself_multiply(self, float val, Size size):
        "self = self * C"
        CHK_HAVEGIL( fw.fwiMulC_32f_C1IR(val, <fw.Fw32f*>self.im, self.step, size.sz))

    cdef void fast_toself_multiply(self, float val, Size size):
        CHK_HAVEGIL( fw.fwiMulC_32f_C1IR(val, <fw.Fw32f*>self.im, self.step, size.sz))

    def get_multiply_put(self, float val, FastImage32f other, Size size):
        "other = self * C"
        CHK_HAVEGIL( fw.fwiMulC_32f_C1R(<fw.Fw32f*>self.im, self.step,  val,
                                          <fw.Fw32f*>other.im,other.step, size.sz))

    def __ipow__(x,y,z):
        cdef FastImage32f xself
        xself = x
        if not z is None:
            raise ValueError("modulo of power not supported")
        if y == 2:
            xself.toself_square(xself.imsiz)
        elif y==0.5:
            xself.toself_sqrt(xself.imsiz)
        else:
            raise ValueError("only 2 and 0.5 powers supported")
        return xself

    def __iadd__(self, object other):
        cdef FastImage8u other8u_base
        cdef square square_op
        if type(other) == square:
            square_op = other
            other8u_base = square_op.base
            assert self.imsiz == other8u_base.imsiz
            self.toself_add_square( other8u_base, self.imsiz)
        else:
            raise TypeError('cannot add type in-place')
        return self

    def __imod__(self, object other):
        cdef FastImage8u other8u
        cdef blend_with blend_width_op
        cdef convert_to_32f convert_to_32f_op
        if type(other) == blend_with:
            blend_width_op = other
            other8u = blend_width_op.other8u
            assert self.imsiz == other8u.imsiz
            self.toself_add_weighted( other8u, self.imsiz, blend_width_op.alpha)
        elif type(other) == convert_to_32f:
            convert_to_32f_op = other
            other8u = convert_to_32f_op.orig8u
            assert self.imsiz == other8u.imsiz
            other8u.get_32f_copy_put(self,self.imsiz)
        else:
            raise TypeError('cannot mod type in-place')
        return self

    def max_index(self, Size size):
        cdef fic.FicStatus sts
        cdef int index_x, index_y
        cdef fic.Fic32f max_val
        cdef fic.FiciSize sz

        sz.width = size.sz.width
        sz.height = size.sz.height
        c_python.Py_BEGIN_ALLOW_THREADS # release GIL
        sts = fic.ficiMaxIndx_32f_C1R(
            <fic.Fic32f*>self.im,self.step,
            sz, &max_val, &index_x, &index_y)
        c_python.Py_END_ALLOW_THREADS # acquire GIL
        CHK_FIC_HAVEGIL(sts)
        return max_val, index_x, index_y

    def dot(self,FastImage32f other,Size size):
        cdef fic.Fic64f result
        cdef fic.FiciSize sz

        sz.width = size.sz.width
        sz.height = size.sz.height
        CHK_FIC_HAVEGIL( fic.ficiDotProd_32f64f_C1R(
            <fic.Fic32f*>self.im,self.step,
            <fic.Fic32f*>other.im,other.step,
            sz, &result ))
        return result

    def sobel_horiz(self, Size size, FastImage32f dest=None):
        cdef fic.FiciSize sz

        sz.width = size.sz.width
        sz.height = size.sz.height
        if dest is None:
            dest = FastImage32f( size )
        else:
            assert dest.size == size
        CHK_FIC_HAVEGIL( fic.ficiFilterSobelHoriz_32f_C1R(<fic.Fic32f*>self.im, self.step, <fic.Fic32f*>dest.im, dest.step, sz ))
        return dest

    def sobel_vert(self, Size size, FastImage32f dest=None):
        cdef fic.FiciSize sz

        sz.width = size.sz.width
        sz.height = size.sz.height
        if dest is None:
            dest = FastImage32f( size )
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
    if not c_python.PyCObject_Check(attr):
        raise ValueError("invalid __array_struct__")

    inter = <PyArrayInterface*>c_python.PyCObject_AsVoidPtr(attr)
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
    if inter.typekind == "u"[0] and inter.itemsize==1:
        result = FastImage8u.__new__(FastImage8u)
##    elif inter.typekind == "b"[0] and inter.itemsize==1: # "bool" true or false
##        result = FastImage8u.__new__(FastImage8u)
    elif inter.typekind == "f"[0] and inter.itemsize==4:
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

def cython_is_broken():

    # This will break cython compilation but not pyrex. That's what we
    # want, since the function (asfastimage) above works with Pyrex
    # 0.9.5.1a and 0.9.6.4 but not Cython 9.8.1.1.

    blech

def copy( object arr ):
    """return a FastImage copy of an array"""
    cdef PyArrayInterface* inter
    cdef FastImageBase result
    cdef int i

    attr = arr.__array_struct__
    if not c_python.PyCObject_Check(attr):
        raise ValueError("invalid __array_struct__")

    inter = <PyArrayInterface*>c_python.PyCObject_AsVoidPtr(attr)
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

    if inter.typekind == "u"[0] and inter.itemsize==1:
        result = FastImage8u(Size(inter.shape[1],inter.shape[0])) # allocate memory
    elif inter.typekind == "f"[0] and inter.itemsize==4:
        result = FastImage32f(Size(inter.shape[1],inter.shape[0])) # allocate memory
    else:
        raise ValueError('typekind "%s", itemsize %d not supported'%(chr(inter.typekind),inter.itemsize))

    # TODO: make sure that we can rely on blocks like this:
    for i from 0 <= i < inter.shape[0]:
        c_lib.memcpy( result.im + i*result.step,
                      inter.data + i*inter.strides[0],
                      inter.shape[1]*result.strides[1] )

    return result

# Some experimental lazy operators to support fast arithmetic using
# normal symbols (e.g. +=).

cdef class LazyOp:
    pass

##############################

cdef class square(LazyOp):
    def __init__(self, FastImageBase base):
        self.base = base

    def __call__(self):
        return self.base.get_square(self.base,self.base.imsiz)

cdef class sqrt(LazyOp):
    def __init__(self, FastImageBase base):
        self.base = base

    def __call__(self):
        return self.base.get_sqrt(self.base,self.base.imsiz)

# for use with %= ############

cdef class blend_with(LazyOp):
    def __init__(self, FastImage8u other8u, float alpha):
        self.other8u = other8u
        self.alpha = alpha

cdef class convert_to_8u(LazyOp):
    def __init__(self, FastImage32f orig32f):
        self.orig32f = orig32f

cdef class convert_to_32f(LazyOp):
    def __init__(self, FastImage8u orig8u):
        self.orig8u = orig8u

