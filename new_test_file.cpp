#include <iostream>
#include <cmath>
int main()
{
    int x,y;
    std::cin >> x >> y; 
    double z = std::sqrt(x*x+y*y);
    std::cout << z << std::endl;
}