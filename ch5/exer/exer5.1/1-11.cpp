#include <iostream>

int main()
{
	int left, right;
	std::cout << "Please input two numbers" 
		  << "(left and right):"
		  << std::endl;
	std::cin >> left >> right;
	
	int i = left;
	while (i <= right) 
		std::cout << i++ << std::endl;

	return 0;
}
