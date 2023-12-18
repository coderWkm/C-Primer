#include <iostream>
#include <string>
#include <vector>

using std::cin; using std::cout;
using std::endl;
using std::string;
using std::vector;
bool isword(string word); 

int main() 
{
	vector<string> words;
	string input;

	while (cin >> input) {
		if (!isword(input))
			cout << "请输入由大小写字母组成的单词" << endl;
		else
			words.push_back(input);
		cout << "下一个单词：";
	}

	for (auto &word : words) {
		for (auto &ch : word) {
			if (islower(ch))
				ch = toupper(ch);
		}
		cout << word << " ";
	}
	cout << endl;
	return 0;
}

bool isword(string word) 
{	
	bool flag = true;
	for (auto ch : word)
	{
		if (!isalpha(ch)) {
			flag = false;
			break;
		}
	}
	return flag;
}
