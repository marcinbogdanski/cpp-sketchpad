#include <iostream>
#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <pybind11/stl.h>

namespace py = pybind11;

class PyQExtract {
private:
    std::string data_folder;
public:
    PyQExtract(
        const std::string &data_folder
    ) : data_folder(data_folder) { }

    py::array_t<double> read_file(
        const std::string &tcap_filename,
        const std::vector<std::string> &symbols
    ) {

        // Create and populate dumb C array
        size_t size = 100;
        double *foo = new double[size];
        for (size_t i = 0; i < size; i++) {
            foo[i] = (double) i;
        }

        // Create Python object that will free memory when destroyed
        py::capsule free_when_done(foo, [](void *f) {
            double *foo = reinterpret_cast<double *>(f);
            std::cerr << "freeing memory @ " << f << "\n";
            delete[] foo;
        });

        // Return numpy array
        return py::array_t<double>(
            {100},          // shape
            {8},            // element size
            foo,            // data pointer
            free_when_done  // pseudo destructor
        );

    }
};

namespace py = pybind11;

PYBIND11_MODULE(pyqextract, m) {
    py::class_<PyQExtract>(m, "PyQExtract")
        .def(py::init<const std::string &>())
        .def("read_file", &PyQExtract::read_file);
}

