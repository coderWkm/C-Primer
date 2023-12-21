#include <iostream>
#include <random>

int main()
{
    std::uniform_real_distribution<double> u(0, 10);
    std::cout << u.min() << ", " << u.max() << std::endl;

    
    return 0;
}