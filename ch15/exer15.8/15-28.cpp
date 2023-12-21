#include <iostream>
#include <vector>
#include <memory>
#include "..\\exer15.7.4\\15-15.h"
int main()
{
    std::vector<Quote> basket;
    Bulk_quote b1("book1", 10, 3, 0.9);
    basket.push_back(b1);
    Bulk_quote b2("book2", 20, 5, 0.8);
    basket.push_back(b2);
    Bulk_quote b3("book3", 30, 8, 0.7);
    basket.push_back(b3);
    Bulk_quote b4("book4", 40, 10, 0.5);
    basket.push_back(b4);
    
    double res = 0.;
    for (auto citer = basket.cbegin(); citer != basket.cend(); ++citer)
        res += citer->net_price(5);
    std::cout << "每种各买5本，net_price:" << res << std::endl;

    return 0;
}
