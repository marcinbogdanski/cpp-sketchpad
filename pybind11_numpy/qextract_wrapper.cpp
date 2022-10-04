
#include <iostream>
#include <variant>

#include "qextract_wrapper.hpp"


any_array_type QExtractPythonWrapper::read_file(
    const std::string &tcap_filename,
    const std::vector<std::string> &symbols
) {
    std::cout << "sizeof long" << sizeof(long) << std::endl;

    // pybind11::array_t<long> nparray_double = create_dummy_long_array();

    std::vector<std::string> vector_string = create_dummy_string_vector();

    // Return numpy array
    return vector_string;

}

np_long_arr QExtractPythonWrapper::create_dummy_long_array() {
    // Create and populate dumb C array
    size_t size = 100;
    long *foo = new long[size];
    for (size_t i = 0; i < size; i++) {
        foo[i] = (long) i;
    }

    // Create Python object that will free memory when destroyed
    pybind11::capsule free_when_done(foo, [](void *f) {
        long *foo = reinterpret_cast<long *>(f);
        std::cerr << "freeing memory @ " << f << "\n";
        delete[] foo;
    });

    // Return numpy array
    return pybind11::array_t<long>(
        {100},           // shape
        {sizeof(long)},  // element size
        foo,             // data pointer
        free_when_done   // pseudo destructor
    );
}

np_double_arr QExtractPythonWrapper::create_dummy_double_array() {
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
        {100},             // shape
        {sizeof(double)},  // element size
        foo,               // data pointer
        free_when_done     // pseudo destructor
    );
}

cpp_str_vect QExtractPythonWrapper::create_dummy_string_vector(){
    std::vector<std::string> result;
    size_t size = 100;
    for (size_t i = 0; i < size; i++){
        result.push_back(std::to_string(i));
    }
    return result;
}