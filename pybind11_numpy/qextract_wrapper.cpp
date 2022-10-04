
#include <iostream>

#include "qextract_wrapper.hpp"


pybind11::array_t<double> QExtractPythonWrapper::read_file(
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
    pybind11::capsule free_when_done(foo, [](void *f) {
        double *foo = reinterpret_cast<double *>(f);
        std::cerr << "freeing memory @ " << f << "\n";
        delete[] foo;
    });

    // Return numpy array
    return pybind11::array_t<double>(
        {100},          // shape
        {8},            // element size
        foo,            // data pointer
        free_when_done  // pseudo destructor
    );

}