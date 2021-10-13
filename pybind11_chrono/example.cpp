#include <pybind11/pybind11.h>
#include <pybind11/chrono.h>
#include <chrono>

std::chrono::time_point<std::chrono::system_clock> get_time() {
    return std::chrono::system_clock::now();
}

PYBIND11_MODULE(example, m) {
    m.doc() = "pybind11 example plugin"; // optional module docstring

    m.def("get_time", &get_time, "A function to get time");
}
