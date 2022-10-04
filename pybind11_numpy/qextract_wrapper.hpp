#ifndef AVATAR_QEXTRACT_WRAPPER_HPP
#define AVATAR_QEXTRACT_WRAPPER_HPP

#include <variant>
#include <pybind11/numpy.h>


class QExtractPythonWrapper {
private:
    std::string data_folder;
public:
    QExtractPythonWrapper(const std::string &data_folder) : data_folder(data_folder) { }

    std::variant<pybind11::array_t<double>, pybind11::array_t<int>> read_file(
        const std::string &tcap_filename,
        const std::vector<std::string> &symbols
    );

    pybind11::array_t<int> create_dummy_int_array();
    pybind11::array_t<double> create_dummy_double_array();
};

#endif  // AVATAR_QEXTRACT_WRAPPER_HPP
