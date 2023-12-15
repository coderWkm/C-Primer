#include <iostream>
#include "Sales_data.hpp"

template <typename T>
int compare(const T &v1, const T &v2)
{
    //if (v1 < v2) return -1;
    //if (v2 < v1) return 1;
    /**
     * 代码区错误提示出现在两个if的<; 详细报错信息：
     *  xxx In instantiation of 'int compare(const T&, const T&) [with T = Sales_data]':
        xxx  required from here
        xxx error: no match for 'operator<' (operand types are 'const Sales_data' and 'const Sales_data')
        if (v1 < v2) return -1;
         ~~~^~~~
        xxx error: no match for 'operator<' (operand types are 'const Sales_data' and 'const Sales_data')
        if (v2 < v1) return 1;
    *
    *
    *   根据错误提示可发现：
    *   1. 先提示是实例化模板函数出现错误：
    *   2. 再提示出现错误的原因：Sales_data类型不匹配<运算符
    */
    return 0;
}

int main()
{
    Sales_data book1("Life"), book2("CppPrimer5th");
    //std::cout << compare(book1, book2) << std::endl;
    
    return 0;
}
