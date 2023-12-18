#include <iostream>
#include "../../example/Sales_item.h"

int main()
{	
	Sales_item total;
	if (std::cin >> total) {
		Sales_item tran;
		while (std::cin >> tran) {
			if (total.isbn() == tran.isbn()) {
				total += tran;
			}
			else {
				std::cout << total << std::endl;
				total = tran;
			}
		}
		std::cout << total << std::endl;
	}
	else {
		std::cout << "No Data!" << std::endl;
		return -1;
	}	
		
	return 0;
}
