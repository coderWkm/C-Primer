#ifndef BASKET
#define BASKET
#include "Bulk_quote.hpp"
#include <memory>
#include <set>

// EXER15.30
class Basket {
public:
    // 这里之前写成 insert(std::make_shared<Quote>(sale.clone())); 
    /*为什么会报错：
    new_allocator.h:136:4: error: no matching function for call to 'Quote::Quote(Quote*)'
    { ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }
    */
    void add_item(const Quote &sale)  { item.insert(std::shared_ptr<Quote>(sale.clone()));}
    void add_item(Quote &&sale)  { item.insert(std::shared_ptr<Quote>(std::move(sale).clone()));}

    double total_receipt(std::ostream &) const;
private:
    static bool compare(const std::shared_ptr<Quote> &lhs, 
                        const std::shared_ptr<Quote> &rhs)
    {   return lhs->isbn() < rhs->isbn(); }
    std::multiset<std::shared_ptr<Quote>, decltype(compare)*> item{compare};
};

double Basket::total_receipt(std::ostream &out) const
{
    double res = 0.;
    for (auto citer = item.cbegin(); citer != item.cend(); citer = item.upper_bound(*citer))
        res += print_total(std::cout, **citer, item.count(*citer));
    return res;
}

#endif