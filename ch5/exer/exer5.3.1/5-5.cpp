#include <iostream>
#include <string>
#include <vector>

using std::cin; using std::cout;
using std::endl;
using std::string; 
using std::vector;

int main() 
{
	int scores;
	string hash_score[] = {"F", "D", "C", "B", "A", "S"};
	string str_score;
	while (cin >> scores) {
		if (scores > 100 || scores < 0) {
			cout << "输入的成绩非法（0-100以外）！" << endl;
			cout << "请重新输入：";
			continue;
		}
		if (scores < 50)
			str_score = hash_score[0];
		else {
			str_score = hash_score[(scores - 50) / 10];
			if (scores != 100) {
				if (scores % 10 > 7)
					str_score += "+";
				else if (scores % 10 < 3)
					str_score += "-";
			}
		}
		cout << "分数：" << scores << " -----> 字母：" << str_score << endl;
		cout << "next：";
	}
	cout << "Done!" << endl;

	return 0;
}
