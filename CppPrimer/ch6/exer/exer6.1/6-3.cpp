#include <iostream>
#include <string>
#include <vector>

using std::cin; using std::cout;
using std::endl;
using std::string; 
using std::vector;

int fact(int num);

int main() 
{
	int input;

	while (cin >> input) {
		cout << input << "!:    "
			 << fact(input) << endl;
	}

	return 0;
}

int fact(int num) 
{
	int res = 1;
	if (!num || num == 1)
		return res;
	else if (num > 1)
	{
		while (num > 1) {
			res *= num;
			--num;
		}
		return res;
	}
	else {
		cout << "输入有误，请输入>0的正整数！"
			 << endl;
		return -1;
	}
}
