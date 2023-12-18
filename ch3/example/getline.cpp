#include <iostream>
#include <string>

using std::cin;
using std::endl; using std::cout;
using std::string;

int main()
{
	string input;
	while (getline(cin, input)) {
		cout << input << endl;
	}
	cout << "xxx" << endl;

	return 0;
}
