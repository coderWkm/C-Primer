#include <iostream>
#include <string>

using std::endl; using std::cin; using std::cout;
using std::string;

struct Sales_data{
	std::string book_name;   // 书名
	std::string book_number;  // 书号/索引
	double price;	// 售价
	unsigned sales_volume; // 销售量
	std::string extra_info;   // 其他信息
};

int main()
{
	Sales_data book1, book2;
	
	cout << "请输入第一本书的信息: 书名、isbn号、\
售价、销售量、其他信息" << endl;
	cin >> book1.book_name;
	cin >> book1.book_number >> book1.price
		     >> book1.sales_volume >> book1.extra_info;
	cout << endl;
	cout << "请输入下一本：" << endl;
	cin >> book2.book_name;
	cin >> book2.book_number >> book2.price
		     >> book2.sales_volume >> book2.extra_info;
	cout << endl;

	if (book1.book_number == book2.book_number &&
		book1.book_name == book2.book_name) {
		cout << book1.book_name << "合并信息：" << endl;
		cout << book1.book_number << book1.price
		     	 << book1.sales_volume + book2.sales_volume
				 << book1.extra_info;
		cout << endl;
		
	}
	
	return 0;
}
