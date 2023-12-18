#include <iostream>

// p34 两个无符号数相减，结果是负数，打印的结果？

int main() 
{
	unsigned u1 = 10, u2 = 42;

	std::cout << u1 - u2 << std::endl;
	// FFFF FFE0，即-32 % 2^32

	return 0;	
}
