#emacs, this is -*-Python-*- mode

cimport c_python
cimport ipp
cimport fic

ctypedef void* fiptr # pointer to FastImage base type

cdef class Size:
    cdef ipp.IppiSize sz

cdef class Point:
    cdef ipp.IppiPoint pt

cdef class FastImageBase:
    cdef fiptr im
    cdef c_python.Py_intptr_t shape[2] # don't use, purely for making __array_struct__ without extra malloc
    cdef c_python.Py_intptr_t strides[2]
    cdef int step # int copy of strides[0], (this could be a problem where int != intptr_t)
    cdef int view
    cdef object basetype
    cdef Size imsiz
    cdef object source_data # keep reference to original image in case it goes out of scope elsewhere

    cdef FastImageBase c_roi( self, int left, int bottom, Size size)

cdef class FastImage32f(FastImageBase) # forward definition

cdef class FastImage8u(FastImageBase):
    cdef void fast_get_absdiff_put(self, FastImage8u other, FastImage8u result, Size size)
    cdef void fast_get_sub_put(self, FastImage8u other, FastImage8u result, Size size)
    cdef void fast_set_val_masked( self, ipp.Ipp8u val, FastImage8u mask, Size size)
    cdef void fast_get_32f_copy_put(self, FastImage32f result,Size size)
    cdef void fast_get_compare_int_put_greater( self, int other_int, FastImage8u dest, Size size)

cdef class FastImage32f(FastImageBase):
    cdef void fast_toself_add_weighted_8u( self, FastImage8u other, Size size, float alpha)
    cdef void fast_toself_add_weighted_32f( self, FastImage32f other, Size size, float alpha)
    cdef void fast_get_8u_copy_put(self,FastImage8u other,Size size)
    cdef void fast_toself_square(self,Size size)
    cdef void fast_get_square_put(self, FastImage32f result, Size size)
    cdef void fast_get_subtracted_put(self,FastImage32f other,FastImage32f result,Size size)
    cdef void fast_toself_multiply(self, float val, Size size)
    cdef FastImage32f create_equal_shape_empty(self, Size size)
