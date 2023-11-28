#include <iostream>
#include "StrVec.h"

int main()
{
    std::initializer_list<std::string> args{"aaa", "bbb", "ccc"};
    StrVec strs(args);
    std::cout << "传入初始化列表构造strs：" << std::endl;
    std::cout << "大小：" << strs.size() << ", ";
    for (auto citer = strs.begin(); citer != strs.end(); ++citer)
        std::cout << *citer << " ";
    std::cout << std::endl;

    StrVec strs2 = strs;
    std::cout << "'='构造strs2：" << std::endl;
    std::cout << "大小：" << strs2.size() << ", ";
    for (auto citer = strs2.begin(); citer != strs2.end(); ++citer)
        std::cout << *citer << " ";
    std::cout << std::endl;

    return 0;
}
