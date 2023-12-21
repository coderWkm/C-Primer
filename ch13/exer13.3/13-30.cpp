#include <iostream>
#include "HasPtr.h"

int main()
{
    HasPtr a("aaaaa"), b("bbbbb");
    std::cout << "交换前：" << std::endl;
    std::cout << "a对象：" << a.get_ps() << "---->" << *(a.get_ps())
              << std::endl;
    std::cout << "b对象：" << b.get_ps() << "---->" << *(b.get_ps())
              << std::endl;
    swap(a, b);
    std::cout << "交换后：" << std::endl;
    std::cout << "a对象：" << a.get_ps() << "---->" << *(a.get_ps())
              << std::endl;
    std::cout << "b对象：" << b.get_ps() << "---->" << *(b.get_ps())
              << std::endl;

    
    return 0;
}
