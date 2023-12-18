#include <iostream>
#include "Sales_data.h"

int main()
{
	Sales_data book1, book2;
	
	std::cout << "请输入第一本书的信息: 书名、isbn号、\
售价、销售量、其他信息" << std::endl;
	std::cin >> book1.book_name;
	std::cin >> book1.book_number >> book1.price
		     >> book1.sales_volume >> book1.extra_info;
	std::cout << std::endl;
	std::cout << "请输入下一本：" << std::endl;
	std::cin >> book2.book_name;
	std::cin >> book2.book_number >> book2.price
		     >> book2.sales_volume >> book2.extra_info;
	std::cout << std::endl;

	if (book1.book_number == book2.book_number &&
		book1.book_name == book2.book_name) {
		std::cout << book1.book_name << "合并信息：" << std::endl;
		std::cout << book1.book_number << book1.price
		     	 << book1.sales_volume + book2.sales_volume
				 << book1.extra_info;
		std::cout << std::endl;
		
	}
	
	return 0;
}
