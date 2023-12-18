#include <iostream>
#include <string>
using std::string;
using std::cin; using std::cout;
using std::endl;

int main()
{
	//读入一整行;
	string input;
	cout << "以行读取:" << endl;
	while (getline(cin, input)) {
		if (input.empty())
			break;
		cout << input << endl;
		cout << "Next string: " << endl;
	}
	
	getline(cin, input);

	cout << "以单词为基准读取：" << endl;
	while (cin >> input) {
		cout << input << endl;
		cout << "Next: " << endl;
	}
	cout << "Done!" << endl;

}
