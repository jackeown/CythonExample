import cythonMiddleware

a,b = 2,3

cAns = cythonMiddleware.cFuncWrapper(a,b)
pyAns = cythonMiddleware.pyFuncWrapper(a,b)

print(f"cAns: {cAns}")
print(f"pyAns: {pyAns}")