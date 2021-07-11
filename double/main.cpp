#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <limits>

int main(){

    double val = 1.0/7.0;
    
    std::stringstream ss;
    ss.precision(std::numeric_limits<double>::max_digits10);

    ss << "Ho Ho Ho " << std::endl;
    ss << val << std::endl;
    ss << val << std::endl;

    std::cout << ss.str();
    
    return 0;
}