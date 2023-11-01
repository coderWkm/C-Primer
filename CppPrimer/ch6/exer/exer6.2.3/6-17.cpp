#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using std::cin; using std::cout;
using std::endl;
using std::string; 
using std::vector;

bool exists_upper_alpha(const string &str);
void upper2lower(string &str);

int main() 
{
	string input;
	while (cin >> input) {
		cout << input << "，该字符换中是否有大写字母(0-否|1-是)：";
		cout << exists_upper_alpha(input) << endl;
		upper2lower(input);
		cout << "大写转换小写：" << input << endl;
		cout << "Next:";
	}

	return 0;
}

void upper2lower(string &str)
{
	string::iterator iter;
	for (iter = str.begin(); iter != str.end(); ++iter) {
		if (isupper(*iter)) {
			*iter = tolower(*iter);
		}
	}
}

bool exists_upper_alpha(const string &str)
{
	bool flag = false;
	string::const_iterator iter;
	for (iter = str.cbegin();
		iter != str.cend(); ++iter) {
		if (isupper(*iter)) {
			flag = true;
			break;
		}
	}
	return flag;
}
