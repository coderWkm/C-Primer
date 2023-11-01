#include <iostream>
#include <string>
#include <vector>

using std::cin; using std::cout;
using std::endl;
using std::string; 
using std::vector;

int main() 
{
	bool flag = false;
	int max_cnt = 0, cur_cnt = 0;
	string cur_str, max_str, pre_str = "";

	while (cin >> cur_str) {
		if (cur_str == pre_str) {
			++cur_cnt;
			if (cur_cnt == max_cnt)
				flag = true;
			if (cur_cnt > max_cnt) {
				max_cnt = cur_cnt;
				max_str = cur_str;
				flag = false;
			}
		}
		else
			cur_cnt = 1;
		pre_str = cur_str;
	}

	if (max_cnt > 1 && !flag) {
		cout << "出现最多次数的是：" << max_str;
		cout << ", 出现次数：" << max_cnt << "次" << endl;
	}
	else if (flag)
		cout << "有出现次数同样多的单词" << endl;
	else
		cout << "所有单词均只出现一次"  << endl;

	return 0;
}
