import sys
sys.path.append(".")

import helpers


cdef extern from "helpers.h": 
    int cFunc(int, int)

cpdef public int cFuncWrapper(int x, int y):
    return cFunc(x,y)

cpdef public int pyFuncWrapper(int x, int y):
    return helpers.pyFunc(x,y)