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
	// 委托构造函数
	Sales_data(const std::string &bname, unsigned bsv, double bprice):
		book_name(bname), sales_volume(bsv), price(bprice) 
	{
		std::cout << "执行委托构造函数" << std::endl;
	}
	// 构造函数
	Sales_data(): Sales_data("NullName", 0, 0.0) 
	{ 
		std::cout << "默认构造函数" << std::endl;
	}
	Sales_data(std::istream &is): Sales_data() 
	{ 
		read(is, *this); 
		std::cout << "提供istream的构造函数" << std::endl;
	}
	Sales_data(const std::string &s): Sales_data(s, 0, 0.0) 
	{ 
		std::cout << "初始化名字的构造函数" << std::endl;
	}
public:
	// 普通成员函数
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
#endif
