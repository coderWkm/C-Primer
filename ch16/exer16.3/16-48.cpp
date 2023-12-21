#include <iostream>
#include <string>
#include <sstream>
template <typename T>
std::string debug_rep(const T &t)
{
    std::ostringstream ret;
    ret << t;
    return ret.str();   
}
template <typename T>
std::string debug_rep(T *t)
{
    std::ostringstream ret;
    ret << "pointer: " << t;
    if (t)
        ret << " " << debug_rep(*t);
    else
        ret << " null pointer";
    return ret.str();
}
std::string debug_rep(const std::string &s) 
{
    return '"' + s + '"';
}
std::string debug_rep(char *p)
{
    return debug_rep(std::string(p));
}
std::string debug_rep(const char *p)
{
    return debug_rep(std::string(p));
}
int main()
{
    std::string s("hi");
    std::cout << debug_rep(s) << std::endl;
    std::cout << debug_rep(&s) << std::endl;
    
    const std::string *p = &s;
    std::cout << debug_rep(p) << std::endl;

    // 增加参数char*的重载函数前：pointer: asedfwer a
    // 因为P615下说过，IO库位char*重载了<<，所以输出的是该字符串内容
    std::cout << debug_rep("asedfwer") << std::endl;  // 增加后："asedfwer"

    return 0;
}
