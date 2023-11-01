#include <iostream>
#include <string>

using std::cin; using std::cout;
using std::endl;
using std::string;

struct Sales_data{
	string book_name;   // 书名
	string book_number;  // 书号/索引
	double price;	// 售价
	unsigned sales_volume; // 销售量
	string extra_info;   // 其他信息
};

int main()
{
	Sales_data input;
	
	cout << "请依次输入: 书名、isbn号、\
售价、销售量、其他信息" << endl;
	while (cin >> input.book_name) {
		cin >> input.book_number >> input.price
				 >> input.sales_volume >> input.extra_info;
		cout << "书名：" << input.book_name << endl;
		cout << "isbn：" << input.book_number << endl;
		cout << "售价：" << input.price << endl;
		cout << "销售量：" << input.sales_volume << endl;
		cout << "其他信息：" << input.extra_info << endl;
		cout << endl;
		cout << "请输入下一本：" << endl;
	}
	cout << "Done!" << endl;
	return 0;
}
