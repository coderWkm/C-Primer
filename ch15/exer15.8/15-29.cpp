#include <iostream>
#include <vector>
#include <memory>
#include "..\\exer15.7.4\\15-15.h"
int main()
{
    std::vector<std::shared_ptr<Quote>> basket;
    Bulk_quote b1("book1", 10, 3, 0.9);
    basket.push_back(std::make_shared<Bulk_quote>(b1));
    Bulk_quote b2("book2", 20, 5, 0.8);
    basket.push_back(std::make_shared<Bulk_quote>(b2));
    Bulk_quote b3("book3", 30, 8, 0.7);
    basket.push_back(std::make_shared<Bulk_quote>(b3));
    Bulk_quote b4("book4", 40, 10, 0.5);
    basket.push_back(std::make_shared<Bulk_quote>(b4));
    
    double res = 0.;
    for (auto citer = basket.cbegin(); citer != basket.cend(); ++citer)
        res += (*citer)->net_price(5);
    std::cout << "每种各买5本，net_price:" << res << std::endl;
    /*
        28练习每次调用的是Quote中的net_price, 因为28中的vector保存的类型是Quote
        29中的vector保存的是Quote的shared_ptr，而Bulk_quote的指针可以转化为Quote的指针，
            但是能够调用指针所指对象真正的动态类型的net_price函数
    */

    return 0;
}
