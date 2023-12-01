#include <iostream>
#include <functional>

int add(int i, int j) {return i + j;}
struct divide {
    int operator()(int i, int j) { return i / j; }
};
int main()
{
    std::function<int(int, int)> f1 = add;
    std::function<int(int, int)> f2 = divide();
    std::function<int(int, int)> f3 = [](int i, int j) {return i * j;};
    std::cout << f1(4, 2) << std::endl;
    std::cout << f2(4, 2) << std::endl;
    std::cout << f3(4, 2) << std::endl;

    return 0;
}
