#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using std::cin; using std::cout;
using std::endl;
using std::string; using std::vector;

// 题目本身的意思可能是说范围for的循环变量
// 没有设置为引用类型的情况

int main() 
{
	string input;
	while (cin >> input) {
		cout << "Original string: " << input << endl;
		if (input.size() > 0)
		{
			for(char &ch : input)
				ch = 'X';
			cout << "New string: " << input << endl;
		}	
		else
			cout << "This is a null string!" << endl;
		cout << "Next: " << endl;
	}
	cout << "Done!" << endl;

	return 0;
}
