#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using std::cin; using std::cout;
using std::endl;
using std::string; 
using std::vector;

int main() 
{
	int num1, num2;
	while (cin >> num1 >> num2) {
		try {
			if (num2 == 0)
				throw std::runtime_error("除数不能为0");
			cout  << "除法结果：" << num1 / num2 << endl;
		} catch (std::runtime_error err) {
			cout << err.what() << endl;
		}
		cout << "next: ";
	}

	return 0;
}
