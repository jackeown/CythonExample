
all: python c

python: 
	python setup.py build_ext --inplace

c: python
	gcc -o main main.c cythonMiddleware.cpython-37m-x86_64-linux-gnu.so \
		-I ~/.pyenv/versions/3.7.0/include/python3.7m \
		-I . \
		-L ~/.pyenv/versions/3.7.0/lib \
		-lpython3.7m \
		-lpthread \
		-lm \
		-lutil \
		-ldl \
		-Wl,-rpath=$(pwd)
