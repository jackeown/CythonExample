#include<stdio.h>
#include<Python.h>
#include "cythonMiddleware.h"


wchar_t* setUpPython(){
    PyObject *pmodule;
    wchar_t* programName = Py_DecodeLocale("program", NULL);

    /* Add a built-in module, before Py_Initialize */
    if (PyImport_AppendInittab("cythonMiddleware", PyInit_cythonMiddleware) == -1) {
        fprintf(stderr, "Error: could not extend in-built modules table\n");
        exit(1);
    }

    Py_SetProgramName(programName);
    Py_Initialize();

    PyImport_ImportModule("cythonMiddleware");

    return programName;
}


void tearDownPython(wchar_t* programName){
    /* Clean up after using CPython. */
    PyMem_RawFree(programName);
    Py_Finalize();
}





int main(int argc, char* argv[])
{
    wchar_t* programName = setUpPython();

    printf("cAns: %d\n", cFuncWrapper(2,3, 0));
    printf("pyAns: %d\n", pyFuncWrapper(2,3, 0));

    tearDownPython(programName);
}