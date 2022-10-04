all: pyqextract

pyqextract: pyqextract.cpp
	c++ -O3 -Wall -shared -std=c++17 -fPIC `python3 -m pybind11 --includes` pyqextract.cpp -o pyqextract`python3-config --extension-suffix`
