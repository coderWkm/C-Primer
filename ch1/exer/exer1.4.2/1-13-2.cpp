#include <iostream>

// p12第2题：p10的for示例

int main()
{
	int sum = 0, val = 10;
	for (; val > 0; --val) {
		sum += val;
	}	
	std::cout << "Sum of 1 to 10 inclusive is "
		  << sum << std::endl;
	return 0;
}
