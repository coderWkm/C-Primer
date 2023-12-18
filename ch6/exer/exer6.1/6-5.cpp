#include <iostream>
#include <string>
#include <vector>

using std::cin; using std::cout;
using std::endl;
using std::string; 
using std::vector;

int get_abs(int value);

int main() 
{
	int num;

	while (cin >> num) {
		cout << num << "的绝对值："
			 << get_abs(num) << endl;
	}

	return 0;
}

int get_abs(int value)
{
	return value >= 0 ? value : -value;
}
