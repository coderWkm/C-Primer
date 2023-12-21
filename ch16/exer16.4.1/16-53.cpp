#include <iostream>

template <typename T>
std::ostream& print(std::ostream &os, const T& t)
{
    return os << t;
}
template <typename T, typename ... Args>
std::ostream& print(std::ostream &os, const T& t, const Args& ... rest)
{
    os << t << ", ";
    return print(os, rest...);
}

int main()
{
    int i = 0;
    std::string s = "Hello";

    print(std::cout, i) << std::endl;
    print(std::cout, i, s) << std::endl;
    print(std::cout, i, s, 42.1, 'A', "End") << std::endl;

    return 0;
}
