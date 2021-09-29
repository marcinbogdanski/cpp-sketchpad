#include <iostream>
#include <thread>
#include <chrono>
#include <pybind11/pybind11.h>

// See also:
// * https://softwareengineering.stackexchange.com/questions/382195/is-it-okay-to-start-a-thread-from-within-a-constructor-of-a-class
// * https://stackoverflow.com/questions/16718663/c-11-start-thread-with-member-function-and-this-as-parameter

class Pet {
public:
    Pet(const std::string &name) : name(name) {
        std::cout << "constructor" << std::endl;
        thread = std::jthread(&Pet::ThreadFunction, this);
    }
    ~Pet() {
        thread.request_stop();
        thread.join();    // technically optional because we use jthread?
        std::cout << "destructor" << std::endl;
    }
    void setName(const std::string &name_) { name = name_; }
    const std::string &getName() const { return name; }
private:
    std::string name;
    std::jthread thread;
    void ThreadFunction(){
        auto stoken = thread.get_stop_token();
        while (!stoken.stop_requested()){
            std::cout << "inside ThreadFunction" << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
        std::cout << "exiting ThreadFunction" << std::endl;
    }
};

namespace py = pybind11;

PYBIND11_MODULE(example, m) {
    py::class_<Pet>(m, "Pet")
        .def(py::init<const std::string &>())
        .def("setName", &Pet::setName)
        .def("getName", &Pet::getName);
}

