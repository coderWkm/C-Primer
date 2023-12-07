#ifndef QUOTE_H_
#define QUOTE_H_
#include <string>
#include <iostream>

class Quote {
public:
    Quote() = default;
    Quote(const std::string &book, double sales_price) : 
        bookNo(book), price(sales_price) { }
    std::string isbn() const {return bookNo;}
    virtual double net_price(std::size_t n) const { return n * price; }
    virtual ~Quote() = default;
    virtual void Debug() const {
        std::cout << bookNo << ", " << price << std::endl;
    }
private:
    std::string bookNo;
protected:
    double price = 0.0;
};
class Disc_quote : public Quote {
public:
    Disc_quote() = default;
    Disc_quote(const std::string &book, double price, 
                std::size_t qty, double disc) :
                Quote(book, price), quantity(qty), discount(disc) 
                {   }
    double net_price(std::size_t) const = 0;
protected:
    std::size_t quantity = 0;
    double discount = 0.0;
};
class Bulk_quote : public Disc_quote {
public:
    /*
    Bulk_quote() = default;
    Bulk_quote(const std::string &book, double p, std::size_t qty, double disc):
        Disc_quote(book, p, qty, disc) { }
    */
    using Disc_quote::Disc_quote;  // 同时，只含有继承的默认构造函数，会生成合成的默认构造函数
    double net_price(std::size_t) const override;
    //void Debug() const override;
};

double Bulk_quote::net_price(std::size_t cnt) const
{
    if (cnt > quantity) 
        return cnt * (1 - discount) * price;
    else
        return cnt * price;
}
/*
void Bulk_quote::Debug() const 
{
    Quote::Debug();
    std::cout << min_qty << ", " << discount << std::endl;
}
*/
double print_total(std::ostream &os, const Quote &item, size_t n)
{
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() 
       << " # sold: " << n << " total due: " << ret << std::endl; 
    return ret;
}
#endif