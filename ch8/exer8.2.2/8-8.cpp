#include <iostream>
#include <fstream>
// 测试P284示例

struct Sales_data{
	std::string book_name;   // 书名
	std::string book_number;  // 书号/索引
	double price;	// 售价
	unsigned sales_volume; // 销售量
	std::string extra_info;   // 其他信息

	std::string isbn() const {return book_number; }
	Sales_data& combine(const Sales_data& item);
};
Sales_data add(const Sales_data&, const Sales_data&); 
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);

int main(int argc, char* argv[])
{
    std::ifstream input("file1.txt", std::ifstream::in);
    std::ofstream output("file2.txt", std::ofstream::app);
    Sales_data total;
    if (read(input, total)) {
        Sales_data trans;
        while (read(input, trans)) {    
            if (total.isbn() == trans.isbn()) {
                total.combine(trans);
            }
            else {
                print(output, total);
                total = trans;
            }
        }
        print(output, total);
    }
    else {
        std::cerr << "No data!" << std::endl;
    }
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

std::ostream &print(std::ostream& output, const Sales_data& item)
{
	output << item.book_name << " " << item.isbn() << " ";
	output <<  item.price << " " << item.sales_volume << " " 
		   << item.extra_info << std::endl;
	return output;
}
std::istream &read(std::istream& input, Sales_data& item)
{
	input >> item.book_name >> item.book_number;
	input >> item.price >> item.sales_volume >> item.extra_info;
	return input;
}