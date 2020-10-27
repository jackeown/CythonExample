from setuptools import Extension, setup
from Cython.Build import cythonize
import os


ext_modules = [
    Extension(
        "cythonMiddleware",
        sources=["cythonMiddleware.pyx", "helpers.c"],
        include_dirs=[os.path.realpath(os.path.dirname(__file__))]
    )
]

setup(
    name="cythonMiddleware",
    ext_modules=cythonize(ext_modules, language_level=3)
)
