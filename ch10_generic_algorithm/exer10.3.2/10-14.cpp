#include <iostream>

int main()
{
    int a = 1, b = 2;
    auto f = [](int a, int b) { return a + b;};
    std::cout << f(a, b) << std::endl;
    return 0;
}
