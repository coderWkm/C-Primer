#include <iostream>

//P35上： -1 * 1 的无符号结果

int main() 
{
	int i = 1;
	unsigned j = -1;
	std::cout << i * j << std::endl;
	// -1 % 2^32

	return 0;	
}
