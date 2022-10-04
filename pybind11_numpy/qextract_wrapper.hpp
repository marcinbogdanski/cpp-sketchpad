#ifndef AVATAR_QEXTRACT_WRAPPER_HPP
#define AVATAR_QEXTRACT_WRAPPER_HPP

#include <pybind11/numpy.h>


class QExtractPythonWrapper {
private:
    std::string data_folder;
public:
    QExtractPythonWrapper(const std::string &data_folder) : data_folder(data_folder) { }

    pybind11::array_t<double> read_file(
        const std::string &tcap_filename,
        const std::vector<std::string> &symbols
    );
};

#endif  // AVATAR_QEXTRACT_WRAPPER_HPP
