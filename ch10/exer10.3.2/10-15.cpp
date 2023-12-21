#include <iostream>

void lambda_two_int();
int main()
{
    lambda_two_int();   
    return 0;
}

void lambda_two_int()
{
    int a = 3;
    auto f = [a](int b) {return a + b;};
    std::cout << "a + b:" << f(4) << std::endl;
}
