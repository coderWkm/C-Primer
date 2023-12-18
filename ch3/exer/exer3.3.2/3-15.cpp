#include <iostream>
#include <vector>
#include <string>

using std::cin; using std::cout;
using std::endl;
using std::vector;
using std::string;

int main() 
{
	string input;
	vector<string> nums;

	while (cin >> input) {
		nums.push_back(input);
	}
	for (auto value : nums)
		cout << value << " ";
	cout << endl;

	return 0;
}
