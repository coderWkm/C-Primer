#include <iostream>
#include "Quote.h"
int main()
{
    Bulk_quote bulk("978-7-121-15535-2", 100, 2, 0.2);    // 派生类对象
    std::cout << std::endl;

    std::cout << "------Bulk_quote bulk1 = bulk------" << std::endl;
    Bulk_quote bulk1 = bulk;
    std::cout << std::endl;

    std::cout << "------Bulk_quote bulk2 = bulk------" << std::endl;
    Bulk_quote bulk2;
    bulk2 = bulk;
    std::cout << std::endl;

    std::cout << "------Bulk_quote bulk3 = std::move(bulk)------" << std::endl;
    Bulk_quote bulk3 = std::move(bulk);
    std::cout << std::endl;
    /*
        暂时没看懂debug的顺序：拷贝构造运算符的输出与赋值构造运算符的输出顺序不一样
        ？
    */

    std::cout << "------Quote quote1 = bulk------" << std::endl;
    Quote quote1 = bulk;
    std::cout << std::endl;

    std::cout << "------Quote quote2 = std::move(bulk)------" << std::endl;
    Quote quote2 = std::move(bulk);
    std::cout << std::endl;
    
    return 0;
}
