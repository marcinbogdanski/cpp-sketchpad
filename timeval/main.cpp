#include <iostream>
#include <chrono>
#include <sys/time.h>
#include <iomanip>

using namespace std;

int main(){
    cout << "Hello World X" << endl;

    struct timeval val;
    gettimeofday(&val, NULL);

    unsigned long now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();

    std::cout << "Chrono ms " << now << std::endl;
    std::cout << "Time sec  " << val.tv_sec << " " << val.tv_usec << std::endl;

    struct tm tms;
    struct tm *tp = ::localtime_r(&val.tv_sec, &tms);

    std::cout << (long)&tms << "  " << (long)tp << std::endl;

    std::cout << (tp->tm_mon + 1) << '/' << tp->tm_mday << '/' << tp->tm_year + 1900 << ' '
                    << std::setfill('0') << std::setw(2) << tp->tm_hour << ':' << std::setw(2) << tp->tm_min << ':' << std::setw(2) << tp->tm_sec << '.'
                    << std::setw(3) << val.tv_usec << ' ' << std::endl;
    
    struct tm tmg;
    tp = ::gmtime_r(&val.tv_sec, &tmg);

    std::cout << (tp->tm_mon + 1) << '/' << tp->tm_mday << '/' << tp->tm_year + 1900 << ' '
                    << std::setfill('0') << std::setw(2) << tp->tm_hour << ':' << std::setw(2) << tp->tm_min << ':' << std::setw(2) << tp->tm_sec << '.'
                    << std::setw(3) << val.tv_usec << ' ' << std::endl;
    // std::milliseconds ms = duration_cast< milliseconds >(system_clock::now().time_since_epoch());

    
    
    return 0;
}