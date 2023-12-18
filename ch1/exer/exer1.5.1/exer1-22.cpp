#include <iostream>
#include "../../example/Sales_item.h"

int main()
{
	Sales_item input, curItem;
	if (std::cin >> curItem) {
		while (std::cin >> input) {
			if (input.isbn() == curItem.isbn()) {
				curItem += input;
			}
			else {
				std::cout << "最后输入书籍的isbn不一致！";
				std::cout << std::endl;
			}
		}
	}
	std::cout << curItem << std::endl;

	return 0;
}
