#include <iostream>
#include "HasPtr.h"

int main()
{
    HasPtr p1("aaaa");
    std::cout << "p1成员：" << std::endl;
    std::cout << "1. i = " << p1.get_i() << std::endl
              << "2. ps: " << p1.get_ps() << "——>" << *(p1.get_ps()) << std::endl
              << "3. use: " << p1.get_use() << "——>" << *(p1.get_use()) << std::endl;
    
    HasPtr p2(p1);
    std::cout << "拷贝构造p2:"  << std::endl;
    std::cout << "1. i = " << p2.get_i() << std::endl
              << "2. ps: " << p2.get_ps() << "——>" << *(p2.get_ps()) << std::endl
              << "3. use: " << p2.get_use() << "——>" << *(p2.get_use()) << std::endl;
            
    HasPtr p3;
    p3 = p1; 
    std::cout << "拷贝赋值运算符=构造p3:"  << std::endl;
    std::cout << "1. i = " << p3.get_i() << std::endl
              << "2. ps: " << p3.get_ps() << "——>" << *(p3.get_ps()) << std::endl
              << "3. use: " << p3.get_use() << "——>" << *(p3.get_use()) << std::endl;
    return 0;
}
