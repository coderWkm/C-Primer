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
		cout << "Original string: " << input << endl;
		if (input.size() > 0)
		{
			for(auto &ch : input)
				ch = 'X';
			cout << "New string: " << input << endl;
		}	
		else
			cout << "This is a null string!" << endl;
		cout << "Next: " << endl;
	}
	cout << "Done!" << endl;

	return 0;
}
