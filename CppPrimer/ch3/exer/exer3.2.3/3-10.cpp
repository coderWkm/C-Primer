#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using std::cin; using std::cout;
using std::endl;
using std::string; using std::vector;

int main() 
{
	string input;
	while (cin >> input) {
		cout << "input: " << input << endl;
		for(auto ch : input) {
			if (!ispunct(ch))
				cout << ch;
		}
		cout << "Next:" << endl;
	}
	cout << "Done!" << endl;

	return 0;
}
