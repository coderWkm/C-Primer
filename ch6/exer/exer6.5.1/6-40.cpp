#include <iostream>
#include <string>
#include <vector>

using std::cin; using std::cout;
using std::endl;
using std::string; 
using std::vector;

string make_plural(size_t ctr, const string &word,
							   const string &ending = "s")
{
	return (ctr > 1) ? word + ending : word;
}

int main() 
{
	size_t cnt = 0;
	string input;
	while (cin >> input && input != "Q") {
		if (input == "success")
			++cnt;
	}
	if (cnt > 1)
		cout << "success: " << make_plural(cnt, "success", "es")
			 << endl;
	else
		cout << "success: " << make_plural(cnt, "success")
			 << endl;
	
	cnt = 0;
	while (cin >> input && input != "Q") {
		if (input == "failure")
			++cnt;
	}
	cout << "failure: " << make_plural(cnt, "failure") << endl;

	return 0;
}

