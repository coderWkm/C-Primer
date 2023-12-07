#include "15-15.h"
#include <iostream>

int main()
{
    Quote q("明朝那些事儿", 59.00);
    print_total(std::cout, q, 5);
    Bulk_quote bq("活着", 36.15, 5, 0.7);
    print_total(std::cout, bq, 10);

    // 15.17
    //Disc_quote q();
    /*
    不允许使用返回抽象类 "Disc_quote" 的函数:C/C++(323)
    15-16.cpp(12, 16): 函数 "Disc_quote::net_price" 是纯虚拟函数
    */
    return 0;
}
