#include <iostream>
#include <string>
#include <vector>

using std::cin; using std::cout;
using std::endl;
using std::string; 
using std::vector;

int main() 
{
	char ch;
	int a_cnt = 0, e_cnt = 0, 
		i_cnt = 0, o_cnt = 0, u_cnt = 0,
		lf_cnt = 0, table_cnt = 0, sp_cnt = 0,
		other_cnt = 0;
	while ( cin.get(ch) ) {  // 易错：<< 会忽略空格等
		switch (ch) {
			case 'a':
			case 'A':
				++a_cnt;
				break;
			case 'e':
			case 'E':
				++e_cnt;
				break;
			case 'i':
			case 'I':
				++i_cnt;
				break;
			case 'o':
			case 'O':
				++o_cnt;
				break;
			case 'u':
			case 'U':
				++u_cnt;
				break;
			case '\t':
				++table_cnt;
				break;
			case ' ':
				++sp_cnt;
				break;
			case '\n':
				++lf_cnt;
				break;
			default:
				++other_cnt;
				break;
		}
	}
	cout << "a/A: " << a_cnt << endl;
	cout << "e/E: " << e_cnt << endl;
	cout << "i/I: " << i_cnt << endl;
	cout << "o/O: " << o_cnt << endl;
	cout << "u/U: " << u_cnt << endl;
	cout << "space: " << sp_cnt << endl;
	cout << "line feed: " << lf_cnt << endl;
	cout << "table: " << table_cnt << endl;
	cout << "other: " << other_cnt << endl;

	return 0;
}
