#include <iostream>
#include <string>
#include <vector>

using std::cin; using std::cout;
using std::endl;
using std::string; 
using std::vector;

int fact(int num);
void interaction(int input); 

int main() 
{
	int input;

	while (1) {
		interaction(input);
	}

	return 0;
}

void interaction(int input) 
{
	cout << "请输数字：";
	cin >> input;
	cout << input << "的阶乘："
		 << fact(input) << endl;
	cout << "下一个，";
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
