#include <iostream>
#include <string>
#include <vector>

using std::cin; using std::cout;
using std::endl;
using std::string; 
using std::vector;

int main() 
{
	int input;
	while (cin >> input) {
		if (input == 42)
			break;
		else
			cout << "Next:";
	}
	cout << "Done" << endl;

	return 0;
}
