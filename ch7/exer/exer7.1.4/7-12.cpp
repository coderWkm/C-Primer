#include <iostream>
#include <string>

using std::cin; using std::cout; using std::endl;
using std::string;
using std::istream; using std::ostream;

struct Sales_data;
istream &read(istream&, Sales_data&);
struct Sales_data{
	string book_name;   // 书名
	string book_number;  // 书号/索引
	double price = 0.0;	// 售价
	unsigned sales_volume = 0; // 销售量
	string extra_info;   // 其他信息

	Sales_data() = default;
	Sales_data(istream &input) { read(input, *this); }
	Sales_data(const string &s): book_number(s) { }
	Sales_data(const string &bname, unsigned bsv, double bprice): 
		book_name(bname), sales_volume(bsv), price(bprice) { }
	string isbn() const {return book_number; }
	Sales_data &combine(const Sales_data &item);
};
Sales_data add(const Sales_data&, const Sales_data&); 
ostream &print(ostream&, const Sales_data&);

int main()
{
	// 1. 默认
	Sales_data s1;
	print(cout, s1) << endl << endl;

	//2. 传入istream
	Sales_data s2(cin);
	print(cout, s2) << endl << endl;

	//3. 传入isbn
	Sales_data s3("123456");
	print(cout, s3) << endl << endl;

	//4. 三个
	Sales_data s4("abc", 5, 20.0);
	print(cout, s4) << endl << endl;
	
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

ostream &print(ostream& output, const Sales_data& item)
{
	output << "关于" << item.book_name << "的信息：" << endl;
	output << "isbn：" << item.isbn() << endl;
	output << "售价：" << item.price << endl;
	output << "销量：" << item.sales_volume << endl;
	output << "其他信息：" << item.extra_info << endl;
	return output;
}
istream &read(istream& input, Sales_data& item)
{
	cout << "分别输入书名、isbn号、售价、销量、其他信息（空格分隔）：";
	input >> item.book_name >> item.book_number;
	input >> item.price >> item.sales_volume >> item.extra_info;
	cout << "输入成功！" << endl;
	return input;
}
