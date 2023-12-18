#include <iostream>
#include <string>
#include <vector>

using std::cin; using std::cout;
using std::endl;
using std::string; 
using std::vector;

int main() 
{
	string s1, s2;
	cin >> s1 >> s2;
	if (s1 == s2)
		cout << s1 << " == " << s2 << endl;
	else
		cout << s1 << " != " << s2 << endl;
	
	// 2个不超过20个字符的C风格字符串
	char str1[21] = {'\0'}, str2[21] = {'\0'};
	cin >> str1 >> str2;
	int l1 = 0, l2 = 0, i, j;
	for (i = 0, j = 0; 
		str1[i] != '\0' && str2[i] != '\0';
		++i, ++j) {
		++l1;
		++l2;
	}
	if (str1[i] != '\0') {
		while (str1[i++] != '\0')
			++l1;
	}
	else if (str2[j] != '\0') {
		while (str2[j++] != '\0')
			++l2;
	}
	if (l1 != l2) {
		cout << "两个c风格字符串的长度不同：" << endl;
		cout << str1 << ", 长度：" << l1 << endl;
		cout << str2 << ", 长度：" << l2 << endl;
		return -1;
	}
	cout << "2个c风格字符串等长" << endl;
	cout << "l1: " << l1 << ", l2: " << l2 << endl;

	for (i = 0; i < l1; ++i) {
		if (str1[i] != str2[i]) {
			cout << "第" << i << "处不一样：" << endl;
			cout << str1 << ", 第" << i << "处：" << str1[i] << endl;
			cout << str2 << ", 第" << i << "处：" << str2[i] << endl;
			return -1;
		}
	}
	cout << "2个c风格字符串相同！" << endl;

	return 0;
}
