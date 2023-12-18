#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>
#include <iostream>

struct Sales_data{
friend Sales_data add(const Sales_data&, const Sales_data&); 
friend std::ostream &print(std::ostream&, const Sales_data&);
friend std::istream &read(std::istream&, Sales_data&);
private:
	std::string book_name;   // 书名
	std::string book_number;  // 书号/索引
	double price = 0.0;	// 售价
	unsigned sales_volume = 0; // 销售量
	std::string extra_info;   // 其他信息
public:
	Sales_data() = default;
	Sales_data(std::istream &);
	Sales_data(const std::string &s): book_number(s) { }
	Sales_data(const std::string &bname, unsigned bsv, double bprice): 
		book_name(bname), sales_volume(bsv), price(bprice) { }
	std::string isbn() const {return book_number; }
	Sales_data &combine (const Sales_data &item);
	std::string get_bookname() const {return book_name; }
};
Sales_data add(const Sales_data&, const Sales_data&); 
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);

Sales_data& Sales_data::combine(const Sales_data& item)
{
	sales_volume += item.sales_volume;
	extra_info =  extra_info + ";" + item.extra_info;
	return *this;
}

Sales_data add(const Sales_data& item1, const Sales_data& item2) 
{
	Sales_data sum = item1;
	sum.combine(item2);
	return sum;
}

std::ostream &print(std::ostream& output, const Sales_data& item)
{
	output << "关于" << item.book_name << "的信息：" << std::endl;
	output << "isbn：" << item.isbn() << std::endl;
	output << "售价：" << item.price << std::endl;
	output << "销量：" << item.sales_volume << std::endl;
	output << "其他信息：" << item.extra_info << std::endl;
	return output;
}
std::istream &read(std::istream& input, Sales_data& item)
{
	std::cout << "分别输入书名、isbn号、售价、销量、其他信息（空格分隔）：";
	input >> item.book_name >> item.book_number;
	input >> item.price >> item.sales_volume >> item.extra_info;
	std::cout << "输入成功！" << std::endl;
	return input;
}
Sales_data::Sales_data(std::istream &input) 
{
	read(input, *this);
}
#endif
