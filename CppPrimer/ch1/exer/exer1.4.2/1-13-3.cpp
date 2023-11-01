#include <iostream>

int main()
{
	int left, right;
	std::cout << "Please input two numbers" 
		  << "(left and right):"
		  << std::endl;
	std::cin >> left >> right;
	
	for (int i = left; i <= right; ++i) {
		std::cout << i << std::endl;
	}

	return 0;
}
