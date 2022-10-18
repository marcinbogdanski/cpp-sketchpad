#include <iostream>

#include <pybind11/pybind11.h>

namespace py = pybind11;

class MyClass {
private:
    py::dict py_in_flight;

public:
    MyClass(py::dict &my_dict) : py_in_flight(my_dict) {

    }
    void assign_item(const std::string &name_) {
        this->py_in_flight["name"] = name_;
    }

    void print_dict() const {

        std::cout << "---vv----vv---" << std::endl;
        for (auto it: this->py_in_flight){


            const std::string& key = py::cast<const std::string>(it.first);
            std::cout << "key=|" << key << "|" << std::endl;

            const py::dict& value_dict = py::cast<const py::dict>(it.second);
            for (auto it_v: value_dict){
                const std::string& key_v = py::cast<const std::string>(it_v.first);
                std::cout << "  key_v=|" << key_v << "|" << std::endl;

                if (py::isinstance<py::str>(it_v.second)) {
                    const std::string& val_v = py::cast<const std::string>(it_v.second);
                    std::cout << "    type(it_v.second)=string  val_v=|" << val_v << "|" << std::endl;
                }
                if (py::isinstance<py::int_>(it_v.second)) {
                    const int& val_v = py::cast<const int>(it_v.second);
                    std::cout << "    type(it_v.second)=int  val_v=|" << val_v << "|" << std::endl;
                }
                if (py::isinstance<py::float_>(it_v.second)) {
                    const double& val_v = py::cast<const double>(it_v.second);
                    std::cout << "    type(it_v.second)=float  val_v=|" << val_v << "|" << std::endl;
                }
            }
            // std::unordered_map<std::string, double>& a_map =
            //     py::cast <std::unordered_map<std::string, double> >(it.second);

            // const py::dict& values = reinterpret_cast<const py::dict&>(it.second);
            // int xxx = it.first;

            // std::cout << " - locate_client_nm.cpp - INFO - " << this->client_name << ": ";
            // std::cout << key << ": ";
            // for (auto it2: values){
            //     const std::string& field_name = reinterpret_cast<const std::string&>(it.first);
            //     // const py::dict& value2 = reinterpret_cast<const py::dict&>(it.second);

            //     std::cout << field_name << "= ";
            // }
            // std::cout << std::endl;

            // 
            //             << it->first << ": "
            //             << "status=" << it->second.status << " "
            //             << "sym=" << it->second.symbol << " "
            //             << "req_qty=" << it->second.quantity << " "
            //             << "prov=" << it->second.provider << " "
            //             << "offered_qty=" << it->second.offered_qty << " "
            //             << "offered_price=" << it->second.offered_price << " "
            //             << "error=" << it->second.error_msg << " "
            //             

        }
        std::cout << "---^^----^^--" << std::endl;


    }

};


PYBIND11_MODULE(example, m) {
    py::class_<MyClass>(m, "MyClass")
        .def(py::init<py::dict &>())
        .def("assign_item", &MyClass::assign_item)
        .def("print_dict", &MyClass::print_dict);
}

