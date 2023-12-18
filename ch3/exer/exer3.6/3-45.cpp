#include <iostream>
#include <string>
#include <vector>

using std::cin; using std::cout;
using std::endl;
using std::string; 
using std::vector;

int main() 
{
	int ia[3][4] = {
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
	};
	cout << "1. 范围for迭代：" << endl;
	for (auto &p : ia) {
		for (auto &q : p)
			cout << q << " ";
		cout << endl;
	}
	cout << endl;

	cout << "2. 普通for+下标迭代: " << endl;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 4; ++j)
			cout << ia[i][j] << " ";
		cout << endl;
	}
	cout << endl;

	cout << "3. 普通for+指针迭代：" << endl;
	auto p = ia;
	auto q = *p;
	for (;p < ia + 3; ++p) {
		for (;q < *p + 4; ++q)
			cout << *q << " ";
		cout << endl;
	}
	cout << endl;

	return 0;
}
