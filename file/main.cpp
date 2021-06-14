#include <iostream>
#include <fstream>
#include <vector>
#include <unistd.h>

// Notes:
// - std::endl will flush the output console or file stream

int main(){
    std::ofstream file;
    file.open("output.txt");

    std::cout << "Hello File!" << std::endl;
    file      << "Hello File!" << std::endl;

    for (int i = 0; i < 10; i++){
        std::cout << "We are at i = " << i << std::endl;
        file      << "We are at i = " << i << std::endl;
        usleep(1000000);
    }

    std::cout << "Bye File!" << std::endl;
    file      << "Bye File!" << std::endl;

    file.close();
    return 0;
}