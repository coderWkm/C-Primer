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
	string word1, word2;
	while (cin >> word1 >> word2) {
		if (word1 == word2) {
			auto iter = word1.cbegin();
			for (; iter != word1.cend();
				++iter) {
				if (!isupper(*iter))
					break;
			}
			if (iter == word1.cend())
				flag = true;
			else
				continue;
		}
	}
	if (flag) {
		cout << "有两个单词" << word1 << "一样" << endl;
	}
	else
		cout << "没有两次一样的单词" << endl;

	return 0;
}
