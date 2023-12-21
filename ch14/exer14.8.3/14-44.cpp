#include <iostream>
#include <functional>
#include <string>
#include <map>

int add(int i, int j) {return i + j;}
struct divide {
    int operator()(int i, int j) { return i / j; }
};
int main()
{
    std::map<std::string, std::function<int(int, int)>> binops;
    binops["+"] = add;
    binops["-"] = std::minus<int>();
    binops["*"] = [](int i, int j) {return i * j;};
    binops["/"] = divide();
    binops["%"] = std::modulus<int>();
    std::cout << binops["+"](10, 5) << std::endl;
    std::cout << binops["-"](10, 5) << std::endl;
    std::cout << binops["*"](10, 5) << std::endl;
    std::cout << binops["/"](10, 5) << std::endl;
    std::cout << binops["%"](10, 5) << std::endl;

    return 0;
}
