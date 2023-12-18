#include <iostream>

// p11 for循环实例

int main()
{
	int sum = 0;
	for (int val = 1; val <= 10; ++val) {
		sum += val;
	}
	std::cout << "Sum of 1 to 10 : " << sum << std::endl; 

	return 0;
}
