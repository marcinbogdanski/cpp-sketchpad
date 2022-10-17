#include <pybind11/pybind11.h>

namespace py = pybind11;

class Pet {
public:
    Pet(py::dict &my_dict) : my_dict(my_dict) { }
    void setName(const std::string &name_) {
        this->my_dict["name"] = name_;
    }
    std::string getName() const {
        std::string name = py::cast<std::string>(this->my_dict["name"]);
        return name;
    }
private:
    py::dict my_dict;
};

PYBIND11_MODULE(example, m) {
    py::class_<Pet>(m, "Pet")
        .def(py::init<py::dict &>())
        .def("setName", &Pet::setName)
        .def("getName", &Pet::getName);
}

