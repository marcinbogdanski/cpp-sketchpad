#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main(){

    // Save stream properities
    std::ios cout_fmt(NULL);
    cout_fmt.copyfmt(std::cout);

    int w1, w2, w3;
    char f1, f2, f3;
    w1 = std::cout.width();
    f1 = std::cout.fill();
    std::cout << std::setw(3) << std::setfill('0');
    w2 = std::cout.width();
    f2 = std::cout.fill();
    std::cout << 9;
    w3 = std::cout.width();
    f3 = std::cout.fill();
    std::cout << std::endl;

    std::cout << "widths: " << w1 << " " << w2 << " " << w3 << std::endl;
    std::cout << "fills:  " << f1 << " " << f2 << " " << f3 << std::endl;

    // Restore stream
    std::cout.copyfmt(cout_fmt);

}