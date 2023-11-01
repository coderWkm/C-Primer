#include <iostream>
// p13 1.4.3 实例(Ctrl+d是eof)

int main()
{
	int sum = 0, value = 0;
	while (std::cin >> value) {
		sum += value;
	}
	std::cout << "Sum is: " << sum << std::endl;

	return 0;
}
