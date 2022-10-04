#ifndef AVATAR_QEXTRACT_WRAPPER_HPP
#define AVATAR_QEXTRACT_WRAPPER_HPP

#include <map>
#include <variant>
#include <pybind11/numpy.h>

typedef pybind11::array_t<double> np_double_arr;
typedef pybind11::array_t<long> np_long_arr;
typedef std::vector<std::string> cpp_str_vect;

typedef std::variant<np_double_arr, np_long_arr, cpp_str_vect> any_array_type;

// Class that wraps Avatar qextract
// Currently this is dummy example to show C++/Python interaction
// Instead of printing ASCII, this one returns data as numpy arrays to Python
class QExtractPythonWrapper {
private:
    std::string data_folder;
public:
    // Create data reader
    // params:
    // - data_folder - presumably need to pass path to history3, e.g. "/mnt/data_v1/capture/history3"
    QExtractPythonWrapper(const std::string &data_folder) : data_folder(data_folder) { }

    // Read data file
    // params:
    // - tcap_filename - file to read, e.g. "BarRecord-20220913._1h.tcap"
    // - symbols - list of symbols to read, e.g. {"SPY", "AAPL"}
    std::map<std::string, any_array_type> read_file(
        const std::string &tcap_filename,
        const std::vector<std::string> &symbols
    );

    // Dummy functions to show how to create numpy arrays in C++
    np_long_arr create_dummy_long_array();
    np_double_arr create_dummy_double_array();
    cpp_str_vect create_dummy_string_vector();
};

#endif  // AVATAR_QEXTRACT_WRAPPER_HPP
