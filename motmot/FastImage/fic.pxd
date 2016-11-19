cdef extern from "fic.h" nogil:
    ctypedef int FicStatus
    ctypedef unsigned char Fic8u
    ctypedef float Fic32f
    ctypedef double Fic64f
    ctypedef struct FiciSize:
        int width
        int height
    ctypedef int ficMomentState_64f
    FicStatus ficMomentInitAlloc_64f(ficMomentState_64f**)
    FicStatus ficMomentFree_64f( ficMomentState_64f* )

    const char* ficGetErrorString(FicStatus)
