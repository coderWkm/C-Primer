#include <iostream>
#include "../../example/Sales_item.h"

int main()
{
	Sales_item curItem, item;
	int index = 1; // 记录输入的书的索引
	if (std::cin >> curItem) {
		while (std::cin >> item) {
			// 以isbn号区分
			if (item.isbn() == curItem.isbn()) {
				curItem += item;
			}
			else { // 新item
				std::cout << index << ": ";
				std::cout << curItem << std::endl;
				++index;
				curItem = item;
			}
		}
	}	
	// 输出最后一个
	std::cout << index << ": ";
	std::cout << curItem << std::endl;

	return 0;
}
