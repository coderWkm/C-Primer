#ifndef QUOTE_H_
#define QUOTE_H_
#include <string>
#include <iostream>
#include <utility>
class Quote {
public:
    Quote() = default;
    Quote(const std::string &book, double sales_price) : 
        bookNo(book), price(sales_price) { }
    Quote(const Quote &copy) : bookNo(copy.bookNo), price(copy.price)
    {
         std::cout << "Quote拷贝构造函数" << std::endl;
    }
    Quote(Quote &&move) : bookNo(move.bookNo), price(move.price)
    {
        std::cout << "Quote移动构造函数" << std::endl;
    }
    Quote &operator=(const Quote &rhs)
    {
        std::cout << "Quote拷贝赋值运算符" << std::endl;
        if (this != &rhs) {
            price = rhs.price;
            bookNo = rhs.bookNo;
        }
        return *this;
    }
    Quote &operator=(Quote &&rhs)
    {
        std::cout << "Quote移动赋值运算符" << std::endl;
        if (this != &rhs) {
            price = std::move(rhs.price);
            bookNo = std::move(rhs.bookNo);       
        }
        return *this;
    }
    std::string isbn() const {return bookNo;}
    virtual double net_price(std::size_t n) const { return n * price; }
    virtual ~Quote()  { std::cout << "Quote析构函数" << std::endl; }
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
    Disc_quote(const Disc_quote &dq) : 
        Quote(dq), quantity(dq.quantity), discount(dq.discount)
    {
        std::cout << "Disc_quote拷贝构造函数" << std::endl;
    }
    Disc_quote(Disc_quote &&mdq) : 
        Quote(std::move(mdq)), 
        quantity(std::move(mdq.quantity)), discount(std::move(mdq.discount)) 
    {
        std::cout << "Disc_quote移动构造函数" << std::endl;
    }
    Disc_quote &operator=(const Disc_quote &rhs)
    {
        std::cout << "Disc_quote拷贝赋值运算符" << std::endl;
        if (this != &rhs) {
            Quote::operator=(rhs); // 为基类部分赋值
            discount = rhs.discount;
            quantity = rhs.quantity;
        }
        return *this;
    }
    Disc_quote &operator=(const Disc_quote &&rhs)
    {
        std::cout << "Disc_quote移动赋值运算符" << std::endl;
        if (this != &rhs) {
            Quote::operator=(rhs); // 为基类部分赋值
            discount = std::move(rhs.discount);
            quantity = std::move(rhs.quantity);
        }
        return *this;
    }
    ~Disc_quote() override { std::cout << "Disc_quote析构函数" << std::endl; }
    double net_price(std::size_t) const = 0;
protected:
    std::size_t quantity = 0;
    double discount = 0.0;
};
class Bulk_quote : public Disc_quote {
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string &book, double p, std::size_t qty, double disc):
        Disc_quote(book, p, qty, disc) { }
    Bulk_quote(const Bulk_quote &copy):
        Disc_quote(copy)
    {
        std::cout << "Bulk_quote拷贝构造函数" << std::endl;
    }
    Bulk_quote(Bulk_quote &&move):
        Disc_quote(std::move(move))
    {
        std::cout << "Bulk_quote移动构造函数" << std::endl;
    }
    Bulk_quote &operator=(const Bulk_quote &rhs)
    {
        Disc_quote::operator=(rhs); // 为基类部分赋值
        std::cout << "Bulk_quote拷贝赋值运算符" << std::endl;
        return *this;
    }
    Bulk_quote &operator=(Bulk_quote &&rhs)
    {
        Disc_quote::operator=(rhs); // 为基类部分赋值
        std::cout << "Bulk_quote移动赋值运算符" << std::endl;
        return *this;
    }
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