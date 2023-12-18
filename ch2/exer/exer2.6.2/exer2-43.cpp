#include <iostream>

struct Sales_data{
	std::string book_name;   // 书名
	std::string book_number;  // 书号/索引
	double price;	// 售价
	unsigned sales_volume; // 销售量
	std::string extra_info;   // 其他信息
};

void input_bookinfo(Sales_data &res);

int main()
{
	Sales_data cur;
	int tmp_volume = 0, flag = 1;
	while (flag == 1) {
		input_bookinfo(cur);
		tmp_volume += cur.sales_volume;
		std::cout << "输入1，继续读入下一本书：";
		flag = 0;
		std::cin >> flag;
	}
	std::cout << "总销售：" << tmp_volume << std::endl;
	return 0;
}

void input_bookinfo(Sales_data &res)
{
	std::cout << "请输入信息：书名、isbn、售价、销售量、其他信息";
	std::cout << std::endl;
	std::cin >> res.book_name >> res.book_number >> res.price
			 >> res.sales_volume >> res.extra_info;
	std::cout << "输入完成！" << std::endl;
}
