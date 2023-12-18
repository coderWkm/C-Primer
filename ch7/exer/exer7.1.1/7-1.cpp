#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::endl; using std::cout;
using std::string; using std::vector;

struct Sales_data{
	string book_name;   // 书名
	string book_number;  // 书号/索引
	double price;	// 售价
	unsigned sales_volume; // 销售量
	string extra_info;   // 其他信息
};
void read_saledata(Sales_data& book);
string isbn(const Sales_data& book);
void print_book(const Sales_data& book);

int main()
{
	Sales_data trans, total;
	read_saledata(total);
	if (!total.book_name.empty()) {
		read_saledata(trans);
		while (!trans.book_name.empty()) {
			if (isbn(trans) == isbn(total)) {
				total.sales_volume += trans.sales_volume;
			}
			else {
				print_book(total);
				cout << "************Next:***********" << endl;
				total = trans;
			}
			char choice;
			cout << "是否继续输入（y/n）：" ;
			cin >> choice;
			if (choice == 'y' || choice == 'Y') 
				read_saledata(trans);
			else {
				print_book(total);
				break;
			}	 
		}
		cout << "Done!"  << endl;
	}
	else {
		std::cerr << "书名不能为空！" << endl;
		return -1;
	}

	return 0;
}

string isbn(const Sales_data& book) 
{
	return book.book_number;
}
void read_saledata(Sales_data& book)
{
	cout << "请输入书目的以下信息：";
	cout << "书名、isbn号码、价格、销售量、其他信息" << endl;
	cin >> book.book_name;
	cin >> book.book_number;
	cin >> book.price;
	cin >> book.sales_volume;
	cin >> book.extra_info;
}
void print_book(const Sales_data& book) 
{
	cout << book.book_name << "的信息：" << endl;
	cout << "价格：" << book.price << endl;
	cout << "ibsn号码：" << book.book_number << endl;
	cout << "销售量：" << book.sales_volume << endl;
	cout << "其他信息："  << book.extra_info << endl;
}
