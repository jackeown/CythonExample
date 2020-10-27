
# Example of Using Cython with both C and Python
### This repository serves as a minimal example of how to use Cython with both python and C.

This example has only been tested on Linux, but I would imagine that there would only require minimal tweaking to get it working on other operating systems.
(feel free to make a pull request ;))

I assume an example where you want to have helper functions written in both *C* (`helpers.c` and `helpers.h`) and *Python* (`helpers.py`) being called from both a *Python* script (`main.py`) and a *C* program (`main.c`)

The Makefile has two targets:
+ The python target runs the setup.py script for building the Cython interface's shared object file.
+ The C target runs GCC to link `main.c` with the shared object files and other necessary libraries.

Simply running "make" or "make all" will build both targets resulting in a `main.c` file and a cythonMiddleware shared object file.  `main.py` should now work using this shared object file.

One problem with the approach I'm currently using is that `cythonMiddleware.pyx` doesn't know where to find `helpers.py` if `main.py` is being called from a different folder. (The solutions to this include making everything a python package and more `sys.path.append()` hacking...I wish I knew a better way)
