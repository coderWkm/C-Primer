#include <iostream>

int main() 
{
	int i = 1, &ri = i;
	i = 5;
	std::cout << "i: " << i << std::endl;
	std::cout << "ri: " << ri << std::endl;

	ri = 10;
	std::cout << "i: " << i << std::endl;
	std::cout << "ri: " << ri << std::endl;

	return 0;	
}
