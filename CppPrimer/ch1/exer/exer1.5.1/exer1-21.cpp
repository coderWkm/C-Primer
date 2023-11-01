#include <iostream>
#include "../../example/Sales_item.h"

int main()
{
	Sales_item book1, book2;
	while (std::cin >> book1 >> book2) {
		std::cout << "book1 + book2: ";
		std::cout << book1 + book2 << std::endl;
	}

	return 0;
}
