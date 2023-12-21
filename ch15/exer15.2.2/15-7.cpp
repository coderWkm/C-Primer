#include <iostream>
class CheapBook {
public:
    CheapBook() = default;
    CheapBook(const std::string &num, double price, double p, size_t m): 
        bookNo(num), price(price), maxNum(m), discount(p) { }
    virtual double net_price(size_t cnt) 
    { 
        return cnt > maxNum ? maxNum * discount * price : cnt * discount * price;
    }
    virtual ~CheapBook() = default;
private:
    std::string bookNo;
protected:
    double price;
    double discount;
    size_t maxNum;
};

class ExtraBook: public CheapBook {
public:
    ExtraBook() = default;
    ExtraBook(const std::string &num, double price, double p, size_t m):
        CheapBook(num, price, p, m) { }
    double net_price(size_t cnt) override 
    {
        if (cnt > maxNum)
            return CheapBook::net_price(cnt) + (cnt - maxNum) * price;
        else
            return CheapBook::net_price(cnt);
    }
    ~ExtraBook() { }
};

int main()
{
    // CheapBook b1("book1", 25, 0.7, 10);
    ExtraBook b2("Book1", 25, 0.7, 10);
    std::cout << "买5本花费：" << b2.net_price(5) << std::endl;
    std::cout << "买15本花费："  << b2.net_price(15) << std::endl;
    return 0;
}
