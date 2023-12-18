#include <iostream>
/*
	P39下:检验int的四种初始化
*/

int main() 
{
	int b, a;
	std::cout << "Before initalizing: a = " << a << std::endl;
	
	a = 0;
	std::cout << "After =, a = " << a << std::endl;
	
	std::cout << "Before initalizing: b = " << a << std::endl;
	b = {0};
	std::cout << "After ={}, b = " << b << std::endl;
	
	int c{0};
	std::cout << "After {}, c = " << c << std::endl;

	int d(0);
	std::cout << "After (), d = " << d << std::endl;

	return 0;	
}
