#include <iostream>
#include <string>

using std::cin; using std::cout; using std::endl;
using std::istream; using std::ostream;

struct Sales_data{
	string book_name;   // 书名
	string book_number;  // 书号/索引
	double price;	// 售价
	unsigned sales_volume; // 销售量
	string extra_info;   // 其他信息

	string isbn() const {return book_number; }
	Sales_data& combine(const Sales_data& item);
};
Sales_data add(const Sales_data&, const Sales_data&); 

int main()
{
	return 0;
}

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
