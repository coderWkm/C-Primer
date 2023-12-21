#include <iostream>
#include "15-15.h"
int main()
{
    Bulk_quote bq; //  检测编译器默认构造函数是否存在
    std::cout << "bq isbn: " << bq.isbn() << std::endl;
    std::cout << bq.net_price(1) << std::endl;
    Bulk_quote bq2("book", 15, 3, 0.8);
    std::cout << "bq2 isbn: " << bq2.isbn() << std::endl;
    std::cout << bq2.net_price(5) << std::endl;
    return 0;
}
