#ifndef AVATAR_QEXTRACT_WRAPPER_HPP
#define AVATAR_QEXTRACT_WRAPPER_HPP

#include <variant>
#include <pybind11/numpy.h>

typedef pybind11::array_t<double> np_double_arr;
typedef pybind11::array_t<long> np_long_arr;
typedef std::vector<std::string> cpp_str_vect;

typedef std::variant<np_double_arr, np_long_arr, cpp_str_vect> any_array_type;

class QExtractPythonWrapper {
private:
    std::string data_folder;
public:
    QExtractPythonWrapper(const std::string &data_folder) : data_folder(data_folder) { }

    any_array_type read_file(
        const std::string &tcap_filename,
        const std::vector<std::string> &symbols
    );

    np_long_arr create_dummy_long_array();
    np_double_arr create_dummy_double_array();
    cpp_str_vect create_dummy_string_vector();
};

#endif  // AVATAR_QEXTRACT_WRAPPER_HPP
