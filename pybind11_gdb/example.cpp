#include <pybind11/pybind11.h>

#include <signal.h>
#include <iostream>

int add(int i, int j) {
    std::cout << "hello" << std::endl;
    *(char *)0 = 0;
    std::cout << "bye" << std::endl;
    return i + j;
}

PYBIND11_MODULE(example, m) {
    m.doc() = "pybind11 example plugin"; // optional module docstring

    m.def("add", &add, "A function which adds two numbers");
}
