#include <iostream>

using std::cin; using std::cout;
using std::endl;

struct Sales_data{
	string book_name;   // 书名
	string book_number;  // 书号/索引
	double price;	// 售价
	unsigned sales_volume; // 销售量
	string extra_info;   // 其他信息

	string isbn() const {return book_number; }
	Sales_data& combine(const Sales_data& item);
};


int main()
{
	return 0;
}

Sales_data& Sales_data::combine(const Sales_data& item)
{
	if (book_number != item.book_number) {
		cout << item.book_name << "书号：" << item.book_number;
		cout << ", " << this->book_name << "书号：" << this->book_number;
		cout << endl;
		cout << "请确保isbn号一致！" << endl;
		return;
	}
	sales_volume += item.sales_volume;
	extra_info =  extra_info + ";" + item.extra_info;
	return *this;
}
