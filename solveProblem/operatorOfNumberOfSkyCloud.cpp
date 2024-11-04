#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;
int main()
{
    int a = 2;
    int b = 5;
    auto c = static_cast<double>(1 - b);
    c /= 3;
    double factor = std::pow(10, 3);
    double truncValue = std::trunc(c * factor) / factor;
    std::cout << c << std::endl;
    cout << truncValue << endl;
    return 0;
}