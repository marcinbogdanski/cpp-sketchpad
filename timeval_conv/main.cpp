#include <iostream>
#include <chrono>
#include <sys/time.h>
#include <iomanip>

using namespace std;

int main(){
    cout << "Hello World X" << endl;

    struct timeval val;
    gettimeofday(&val, NULL);

    std::cout << "Time sec  " << val.tv_sec << " " << val.tv_usec << std::endl;

    struct tm tms;
    struct tm *tp = ::localtime_r(&val.tv_sec, &tms);

    std::cout << (tp->tm_mon + 1) << '/' << tp->tm_mday << '/' << tp->tm_year + 1900 << ' '
                    << std::setfill('0') << std::setw(2) << tp->tm_hour << ':' << std::setw(2) << tp->tm_min << ':' << std::setw(2) << tp->tm_sec << '.'
                    << std::setw(3) << val.tv_usec << ' ' << std::endl;
    
    std::chrono::time_point<std::chrono::system_clock> chrono_time(
        std::chrono::seconds(val.tv_sec) + std::chrono::microseconds(val.tv_usec));
    
    std::time_t t = std::chrono::system_clock::to_time_t(chrono_time);
    std::cout << std::put_time( std::localtime( &t ), "%FT%T%z" ) << std::endl;

    std::chrono::time_point<std::chrono::system_clock> now_chrono = std::chrono::system_clock::now();
    std::time_t t2 = std::chrono::system_clock::to_time_t(now_chrono);
    std::cout << std::put_time( std::localtime( &t2 ), "%FT%T%z" ) << std::endl;

    return 0;
}