#include <iostream>
#include "StrVec.h"
#include <initializer_list>

int main()
{
    std::initializer_list<std::string> s{"c++", "primer", "5th"};
    StrVec vec_list{s};
    StrVec vec_list2{"c++", "primer", "5th"};
    if (vec_list == vec_list2)
        for (const auto &str : vec_list2)
            std::cout << str << " ";
    std::cout << std::endl;
    return 0;
}