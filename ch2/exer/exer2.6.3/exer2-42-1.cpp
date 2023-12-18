#include <iostream>
#include "Sales_data.h"

int main()
{
	Sales_data input;
	
	std::cout << "请依次输入: 书名、isbn号、\
售价、销售量、其他信息" << std::endl;
	while (std::cin >> input.book_name) {
		std::cin >> input.book_number >> input.price
				 >> input.sales_volume >> input.extra_info;
		std::cout << "书名：" << input.book_name << std::endl;
		std::cout << "isbn：" << input.book_number << std::endl;
		std::cout << "售价：" << input.price << std::endl;
		std::cout << "销售量：" << input.sales_volume << std::endl;
		std::cout << "其他信息：" << input.extra_info << std::endl;
		std::cout << std::endl;
		std::cout << "请输入下一本：" << std::endl;
	}
	std::cout << "Done!" << std::endl;
	return 0;
}
