#include <iostream>

int main() 
{
	int i = 10, *pi = &i;
	std::cout << "i: " << i << std::endl;
	std::cout << "*pi: " << *pi << std::endl;
	std::cout << "&i: " << &i << std::endl;
	std::cout << "pi: " << pi << std::endl;
	std::cout << std::endl;

	i = 20;
	std::cout << "i: " << i << std::endl;
	std::cout << "*pi: " << *pi << std::endl;
	std::cout << "&i: " << &i << std::endl;
	std::cout << "pi: " << pi << std::endl;
	std::cout << std::endl;

	*pi = 30;
	std::cout << "i: " << i << std::endl;
	std::cout << "*pi: " << *pi << std::endl;
	std::cout << "&i: " << &i << std::endl;
	std::cout << "pi: " << pi << std::endl;
	std::cout << std::endl;

	return 0;	
}
