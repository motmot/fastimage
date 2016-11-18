#emacs, this is -*-Python-*- mode

# Support for CPython 2.x API (not in CPython 3.x).

from libc.stdio cimport FILE

cdef extern from "Python.h":
    FILE* PyFile_AsFile(object fobj)
