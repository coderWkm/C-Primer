#include <iostream>

int main()
{
    int a;
    while (!std::cin.fail()) {
        std::cin >> a;
        std::cout << a << std::endl;
    }
    return 0;
}
