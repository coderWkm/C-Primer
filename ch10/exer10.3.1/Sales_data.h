/*
头文件来源：https://blog.houhaibushihai.me/archives/di-10-zhang#10.4
*/
#ifndef TEST_SALES_DATA_H
#define TEST_SALES_DATA_H

// Definition of Sales_data class and related functions goes here
#include <iostream>

// 头文件不应包含 using 声明
// using namespace std;

class Sales_data {
public:
    // 4 个构造函数
    Sales_data() = default;
    Sales_data(const std::string &book) : bookNo(book) {}
    Sales_data(const std::string &book, const unsigned num,
               const double sellp, const double salep);
    Sales_data(std::istream &is);

    std::string isbn() const { return bookNo; }
    std::istream &read(std::istream &is, Sales_data &item);

private:                            // 定义私有数据成员
    std::string bookNo;             // 书籍编号，隐士初始化为空串
    unsigned units_sold = 0;        // 销售量，显示初始化为 0
    double sellingprice = 0.0;      // 原始售价，显示初始化为 0.0
    double saleprice = 0.0;         // 实售价格，显示初始化为 0.0
    double discount = 0.0;          // 折扣，显示初始化为 0.0
};

inline bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs) {
    return lhs.isbn() < rhs.isbn();
}

Sales_data::Sales_data(const std::string &book, const unsigned num,
                       const double sellp, const double salep) {
    bookNo = book;
    units_sold = num;
    sellingprice = sellp;
    saleprice = salep;
    if (sellingprice != 0)
        discount = saleprice / sellingprice;    // 计算实际折扣
}

Sales_data::Sales_data(std::istream &is) {
    read(is, *this);
}

std::istream& Sales_data::read(std::istream &is, Sales_data &item) {
    is >> item.bookNo >> item.units_sold >> item.sellingprice
       >> item.saleprice;
    return is;
}

#endif //TEST_SALES_DATA_H
