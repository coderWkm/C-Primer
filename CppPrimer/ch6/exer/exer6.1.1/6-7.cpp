#include <iostream>
#include <string>
#include <vector>

using std::cin; using std::cout;
using std::endl;
using std::string; 
using std::vector;

int func();

int main() 
{
	int cnt = 0;
	cout << "你想调用几次：";
	cin >> cnt;
	for (int i = 0; i < cnt; ++i) {
		cout << "第" << i << "次："
			 << func() << endl;
	}

	return 0;
}

int func()
{
	static int counter = 0;
	return ++counter;
}
