#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <variant>
#include <string>

using namespace std;

int main(){
    int32_t x = 32;
    // std::variant<double, int64_t, char, std::string, std::chrono::time_point<std::chrono::system_clock>> y = x;
    std::variant<double, int64_t> y = (int64_t)x;
    
    return 0;
}