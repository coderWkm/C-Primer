#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using std::cin; using std::cout;
using std::endl;
using std::string; 
using std::vector;
// 模拟遇到第一个‘ ’就是第一文本中的第一行文字
// 这种假设比较理想，实际情况更发杂

int main() 
{
	string sentence, text;

	while (cin >> sentence) {
		text += sentence;
		text += ' ';
		cout << "Next sentence: " << endl;
	}
	cout << "Old text:" << endl;
	cout << text << endl;

	for (auto iter = text.begin(); 
			iter != text.end() && (*iter) != ' '; 
			++iter) {
			*iter = toupper(*iter);		
	}
	cout << text << endl;
	cout << "Done!" << endl;

	return 0;
}
