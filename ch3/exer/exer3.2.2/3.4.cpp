#include <iostream>
#include <string>
#include <vector>

using std::cin; using std::cout;
using std::endl;
using std::string; using std::vector;

int main() 
{
	string str1, str2;
	while (cin >> str1 >> str2) {
		if (str1 == str2)
			cout << "str1: " << str1
				 << "  =  "
				 << "str2: " << str2 << endl;
		if (str1 != str2) {
			if (str1 > str2)
				cout << "str1: " << str1
					 << "  >  "
				 	 << "str2: " << str2 << endl;
			else
				cout << "str1: " << str1
				 	<< "  <  "
				 	<< "str2: " << str2 << endl;
		}

		if (str1.size() == str2.size())
			cout << "str1's length " << str1.size()
				 << "  =  "
				 << "str2's length " << str2.size() << endl;
		if (str1.size() != str2.size()) {
			if (str1.size() > str2.size())	
				cout << "str1's length " << str1.size()
				 	 << "  >  "
				 	 << "str2's length " << str2.size() << endl;
			else
				cout << "str1's length " << str1.size()
				 	 << "  < "
				 	 << "str2's length " << str2.size() << endl;
		}
		cout << "Next:" << endl;
	}
	cout << "Done!" << endl;

	return 0;
}
