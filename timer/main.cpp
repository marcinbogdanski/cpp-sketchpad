#include <iostream>
#include <chrono>
//#include <ctime>


// Function to calculate
// Fibonacci series
long fibonacci(unsigned n)
{
    if (n < 2) return n;
    return fibonacci(n-1) + fibonacci(n-2);
}
  
int main()
{
    // Using time point and system_clock
    std::chrono::time_point<std::chrono::system_clock> start, end;
  
    start = std::chrono::system_clock::now();
    std::cout << "f(42) = " << fibonacci(42) << '\n';
    end = std::chrono::system_clock::now();
  
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
  
    std::cout << "finished computation at " << std::ctime(&end_time)
              << "elapsed time: " << elapsed_seconds.count() << "s\n";
    
    std::chrono::milliseconds test_duration(2000);
    if (elapsed_seconds < test_duration){
        std::cout << "taken less than " << test_duration.count() << " seconds" << std::endl;
    }else{
        std::cout << "taken more than " << test_duration.count() << " seconds" << std::endl;
    }
}
