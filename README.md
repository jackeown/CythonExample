
# Example of Using Cython with both C and Python
## This repository serves as a minimal example of how to use Cython with both python and C.
---

I assume an example where you want to have helper functions written in both *C* (`helpers.c and `helpers.h`) and *Python* (`helpers.py`) being called from both a *Python* script (`main.py`) and a *C* program(`main.c`)

The Makefile has two targets:
+ The python target runs the setup.py script for building the Cython interface's shared object file.
+ The C target runs GCC to link `main.c` with the shared object files and other necessary libraries.
