all: pyqextract

pyqextract: pyqextract.cpp qextract_wrapper.cpp qextract_wrapper.hpp
	c++ -O3 -Wall -shared -std=c++17 -fPIC `python3 -m pybind11 --includes` pyqextract.cpp qextract_wrapper.cpp qextract_wrapper.hpp -o pyqextract`python3-config --extension-suffix`
