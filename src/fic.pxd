cdef extern from "fic.h":
    ctypedef int FicStatus
    ctypedef unsigned char Fic8u
    ctypedef float Fic32f
    ctypedef struct FiciSize:
        int width
        int height
    ctypedef int ficMomentState_64f
    FicStatus ficMomentInitAlloc_64f(ficMomentState_64f**)
    FicStatus ficMomentFree_64f( ficMomentState_64f* )

    FicStatus ficiMaxIndx_8u_C1R( Fic8u*, int, FiciSize,
                                  Fic8u*, int*, int* )
    FicStatus ficiMinIndx_8u_C1R( Fic8u*, int, FiciSize,
                                  Fic8u*, int*, int* )
    FicStatus ficiMaxIndx_32f_C1R( Fic32f*, int, FiciSize,
                                   Fic32f*, int*, int* )
