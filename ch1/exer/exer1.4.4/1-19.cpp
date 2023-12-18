#include <iostream>

int main()
{
	int left, right;
	std::cout << "Please input two numbers" 
		  << "(left and right):"
		  << std::endl;
	std::cin >> left >> right;
	
	if (left > right) {
		int tmp = right;
		right = left;
		left = tmp;
	}

	int i = left;
	while (i <= right) {
		std::cout << i << std::endl;
		++i;
	}

	return 0;
}
