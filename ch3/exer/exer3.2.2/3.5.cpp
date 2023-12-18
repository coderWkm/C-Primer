#include <iostream>
#include <string>
#include <vector>

using std::cin; using std::cout;
using std::endl;
using std::string; using std::vector;

int main() 
{
	string input, res;
	//while (cin >> input)
	//	res += input;
	//cout << "res: " << res << endl;

	// 空格分隔
	while (cin >> input)
		res = res + input + ' ';
	cout << "res: " << res << endl;
	

	return 0;
}
