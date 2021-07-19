#include <iostream>
#include <chrono>
#include <iomanip>

int main()
{
    std::chrono::time_point<std::chrono::system_clock> now_chrono = std::chrono::system_clock::now();
    std::time_t now_time = std::chrono::system_clock::to_time_t(now_chrono);

    // Basic prints
    std::cout << "Basic Prints:" << std::endl;
    std::cout << std::ctime(&now_time);  // adds newline
    std::cout << std::put_time(std::localtime(&now_time), "%Y-%m-%d %X") << std::endl;
    std::cout << std::put_time(std::gmtime(&now_time), "%Y-%m-%dT%X") << std::endl;
    std::cout << std::endl;

    // Extract seconds and microseconds
    std::chrono::_V2::system_clock::duration timepoint = now_chrono.time_since_epoch();
    std::chrono::seconds sec = std::chrono::duration_cast<std::chrono::seconds>(timepoint);
    std::chrono::microseconds usec = std::chrono::duration_cast<std::chrono::microseconds>(timepoint - sec);
    
    // Advanced print
    std::cout << "Advanced Print:" << std::endl;
    std::ios cout_fmt(NULL);
    cout_fmt.copyfmt(std::cout);

    std::cout << std::put_time(std::gmtime(&now_time), "%Y-%m-%dT%X");
    std::cout << "." << std::setfill('0') << std::setw(6) << usec.count() << std::endl;

    std::cout.copyfmt(cout_fmt);

}
