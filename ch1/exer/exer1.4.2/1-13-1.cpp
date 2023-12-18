#include <iostream>

int main()
{
	int res = 0;
	for (int i = 50; i <= 100; ++i) {
	     res += i;
	}
	std::cout << "Sum of 50 to 100: "
		 << res << std::endl;
	return 0;
}
