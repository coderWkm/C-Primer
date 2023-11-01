#include <iostream>
#include "../../example/Sales_item.h"

int main()
{
	Sales_item input;
	while (std::cin >> input)
		std::cout << input << std::endl;

	return 0;
}
