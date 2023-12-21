#include <iostream>
#include <sstream>
#include <string>
#include <vector>
/**
 * 具体可参考：https://blog.houhaibushihai.me/archives/di-16-zhang#16.56
*/
template <typename T> std::string debug_rep(const T& t)
{
    std::ostringstream ret;
    ret << t;
    return ret.str();
}
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

template <typename ... Args>
std::ostream& msgError(std::ostream &os, const Args& ... rest) 
{
    return print(os, debug_rep(rest)...);
}
int main()
{
    msgError(std::cerr, 123, "aaabbb", 2.3, std::string("ao"));
    
    return 0;
}
