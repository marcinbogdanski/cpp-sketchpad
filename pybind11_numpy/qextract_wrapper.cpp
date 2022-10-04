
#include <iostream>
#include <variant>

#include "qextract_wrapper.hpp"


std::variant<pybind11::array_t<double>, pybind11::array_t<int>> QExtractPythonWrapper::read_file(
    const std::string &tcap_filename,
    const std::vector<std::string> &symbols
) {
    std::cout << "sizeof int" << sizeof(int) << std::endl;

    pybind11::array_t<int> nparray_double = create_dummy_int_array();

    // Return numpy array
    return nparray_double;

}

pybind11::array_t<int> QExtractPythonWrapper::create_dummy_int_array() {
    // Create and populate dumb C array
    size_t size = 100;
    int *foo = new int[size];
    for (size_t i = 0; i < size; i++) {
        foo[i] = (int) i;
    }

    // Create Python object that will free memory when destroyed
    pybind11::capsule free_when_done(foo, [](void *f) {
        int *foo = reinterpret_cast<int *>(f);
        std::cerr << "freeing memory @ " << f << "\n";
        delete[] foo;
    });

    // Return numpy array
    return pybind11::array_t<int>(
        {100},          // shape
        {4},            // element size
        foo,            // data pointer
        free_when_done  // pseudo destructor
    );
}

pybind11::array_t<double> QExtractPythonWrapper::create_dummy_double_array() {
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