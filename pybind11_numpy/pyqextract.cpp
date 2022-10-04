#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <pybind11/stl.h>

#include "qextract_wrapper.hpp"

namespace py = pybind11;

PYBIND11_MODULE(pyqextract, m) {
    py::class_<QExtractPythonWrapper>(m, "PyQExtract")
        .def(py::init<const std::string &>())
        .def("read_file", &QExtractPythonWrapper::read_file);
}

