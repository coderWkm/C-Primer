#ifndef BULK_QUOTE
#define BULK_QUOTE
#include "Disc_quote.hpp"
class Bulk_quote : public Disc_quote {
public:
    /*
    Bulk_quote() = default;
    Bulk_quote(const std::string &book, double p, std::size_t qty, double disc):
        Disc_quote(book, p, qty, disc) { }
    */
    using Disc_quote::Disc_quote;  // 同时，只含有继承的默认构造函数，会生成合成的默认构造函数
    double net_price(std::size_t) const override;
    
    Bulk_quote* clone() const & override {return new Bulk_quote(*this);}
    Bulk_quote* clone() && override {return new Bulk_quote(std::move(*this));}
    //void Debug() const override;
};

double Bulk_quote::net_price(std::size_t cnt) const
{
    if (cnt >= quantity) 
        return cnt * (1 - discount) * price;
    else
        return cnt * price;
}

#endif