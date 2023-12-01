#ifndef TEST_SALES_DATA_H
#define TEST_SALES_DATA_H

#include <iostream>
#include <string>

// added overloaded inp:wut, output, addition, and compound-assignment operators
class Sales_data {
    friend std::istream &operator>>(std::istream&, Sales_data&);        // input
    friend std::ostream &operator<<(std::ostream&, const Sales_data&);  // output
    friend Sales_data operator+(const Sales_data&, const Sales_data&);  // addition

public:
    Sales_data(const std::string &s, unsigned n, double p)
        : bookNo(s), units_sold(n), revenue(n * p) { }
    Sales_data() : Sales_data("", 0, 0.0f) { }
    Sales_data(const std::string &s) : Sales_data(s, 0, 0.0f) { }
    Sales_data(std::istream&);

    Sales_data &operator+=(const Sales_data&);          // compound-assignment
    std::string isbn() const { return bookNo; }

    //类型转换运算符
    operator std::string() const 
    { 
        return bookNo + " " +
        std::to_string(units_sold) + " "
        + std::to_string(revenue);
    }
    operator double() const { return revenue;}

private:
    double avg_price() const;

    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0;
};

std::istream &operator>>(std::istream&, Sales_data&);
std::ostream &operator<<(std::ostream&, const Sales_data&);
Sales_data operator+(const Sales_data&, const Sales_data&);

inline
double Sales_data::avg_price() const {
    return units_sold ? revenue / units_sold : 0;
}

#endif //TEST_SALES_DATA_H
