#include <iostream>
class ifElse {
public:
    int operator() (int a, int b, int c) {
        if (a > 0)
            return b;
        return c;
    }
};

int main()
{
    ifElse test;
    std::cout << test(1, 2, 3) << std::endl;
    std::cout << test(-1, 2, 3) << std::endl;
    return 0;
}
