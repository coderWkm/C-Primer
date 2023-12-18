#include <iostream>
#include <string>
#include <vector>

using std::cin; using std::cout;
using std::endl;
using std::string; 
using std::vector;

int cmp(const int num1, const int *num2) { return (num1 > *num2) ? num1 : * num2;}

int main() 
{
	int num1, num2;
	while (cin >> num1 >> num2) {
		cout << num1 << "和" << num2
		<< "的较大值：" << cmp(num1, &num2);
	}

	return 0;
}

