#include <iostream>
#include <string>
#include <vector>

using std::cin; using std::cout;
using std::endl;
using std::string; 
using std::vector;

int main() 
{
	vector<int> scores(11, 0);
	int input;
	while(cin >> input) {
		if (input <= 100) {
			auto iter = scores.begin();
			++(*(iter+(input/10)));
		}
		else
			cout << "输入分数错误（0—100）" << endl;
	}
	
	for (auto value : scores)
		cout << value << " ";
	cout << endl;

	return 0;
}
