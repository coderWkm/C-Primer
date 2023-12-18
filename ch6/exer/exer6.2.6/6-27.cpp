#include <iostream>
#include <string>
#include <vector>
#include <initializer_list>

using std::cin; using std::cout;
using std::endl;
using std::string; 
using std::vector;
using std::initializer_list;

int get_sum(initializer_list<int> list);

int main() 
{
	cout << get_sum({1, 2, 3, 4, 5}) << endl;

	return 0;
}

int get_sum(initializer_list<int> list)
{
	int res = 0;
	// initializer_list至于begin和end，没有const的对应函数
	for (auto ptr = list.begin();   
		ptr != list.end(); ++ptr) {
		res += *ptr;
	}
	return res;
}
