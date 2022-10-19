#include <iostream>

#include <pybind11/pybind11.h>

namespace py = pybind11;

// Info
// How to marshal through py::dict in C++ passing from pybind11:
// * https://stackoverflow.com/questions/70382001/how-to-marshal-through-pydict-in-c-passing-from-pybind11
// How to set values of py::dict in C++?
// * https://stackoverflow.com/questions/63189875/how-to-set-values-of-pydict-in-c

class MyClass {
private:
    py::dict py_in_flight;

public:
    MyClass(py::dict &my_dict) : py_in_flight(my_dict) {

    }
    void assign_mini_item() {
        int new_int = 666;
        this->py_in_flight["2022010100000009"]["assign_me_int"] = py::cast(new_int);

        double new_float = 999.999;
        this->py_in_flight["2022010100000009"]["assign_me_float"] = py::cast(new_float);

        std::string new_string = "HoHoHo";
        this->py_in_flight["2022010100000009"]["assign_me_string"] = py::cast(new_string);
    }

    void assign_item(std::string CI) {
        py::dict new_dict;
        new_dict["CI"] = py::cast(CI);
        new_dict["symbol"] = py::cast("BCDE");
        new_dict["quantity"] = py::cast(456);
        new_dict["provider"] = py::cast("best2");
        new_dict["status"] = py::cast("requested");
        new_dict["offered_qty"] = py::cast(10);
        new_dict["offered_price"] = py::cast(654.321);
        new_dict["error_msg"] = py::cast("");

        this->py_in_flight[py::cast(CI)] = new_dict;

    }

    bool do_check(std::string CI){
        return this->py_in_flight.contains(py::cast(CI));
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

                if (py::isinstance<py::int_>(it_v.second)) {
                    const int& val_v = py::cast<const int>(it_v.second);
                    std::cout << "    type(it_v.second)=int  val_v=|" << val_v << "|" << std::endl;
                }
                if (py::isinstance<py::float_>(it_v.second)) {
                    const double& val_v = py::cast<const double>(it_v.second);
                    std::cout << "    type(it_v.second)=float  val_v=|" << val_v << "|" << std::endl;
                }
                if (py::isinstance<py::str>(it_v.second)) {
                    const std::string& val_v = py::cast<const std::string>(it_v.second);
                    std::cout << "    type(it_v.second)=string  val_v=|" << val_v << "|" << std::endl;
                }
                
            }

        }
        std::cout << "---^^----^^--" << std::endl;


    }

};


PYBIND11_MODULE(example, m) {
    py::class_<MyClass>(m, "MyClass")
        .def(py::init<py::dict &>())
        .def("assign_mini_item", &MyClass::assign_mini_item)
        .def("assign_item", &MyClass::assign_item)
        .def("do_check", &MyClass::do_check)
        .def("print_dict", &MyClass::print_dict);
}

