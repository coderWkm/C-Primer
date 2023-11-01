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
		other_cnt = 0;
	while (cin >> ch && ch != '\n') {
		switch (ch) {
			case 'a':
				++a_cnt;
				break;
			case 'e':
				++e_cnt;
				break;
			case 'i':
				++i_cnt;
				break;
			case 'o':
				++o_cnt;
				break;
			case 'u':
				++u_cnt;
				break;
			default:
				++other_cnt;
				break;
		}
	}
	cout << "a: " << a_cnt << endl;
	cout << "e: " << e_cnt << endl;
	cout << "i: " << i_cnt << endl;
	cout << "o: " << o_cnt << endl;
	cout << "u: " << u_cnt << endl;
	cout << "other: " << other_cnt << endl;

	return 0;
}
