#include <iostream>
#include <string>
#include <vector>

using std::cin; using std::cout;
using std::endl;
using std::string; 
using std::vector;

int main() 
{
	char cur, pre = ' ';
	int ff_cnt = 0, fl_cnt = 0, fi_cnt = 0;
	while ( cin.get(cur) ) {  // 易错：<< 会忽略空格等
		switch (pre) {
			case 'f': {
				switch (cur) {
					case 'f':
						++ff_cnt;
						break;
					case 'l':
						++fl_cnt;
						break;
					case 'i':
						++fi_cnt;
						break;
					default:
						break;
				}
			}
			default:
				break;
		}
		pre = cur;
	}
	cout << "ff: " << ff_cnt << endl;
	cout << "fi: " << fi_cnt << endl;
	cout << "fl: " << fl_cnt << endl;

	return 0;
}
