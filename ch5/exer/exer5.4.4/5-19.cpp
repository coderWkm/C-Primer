#include <iostream>
#include <string>
#include <vector>

using std::cin; using std::cout;
using std::endl;
using std::string; 
using std::vector;

int main() 
{
	string str1, str2;
	do {
		cout << "输入：" << endl;
		cin >> str1 >> str2;
		cout << (str1.size() < str2.size() ? str1 : str2) << endl;
		cout << "下一组：";
	} while (cin);

	return 0;
}
