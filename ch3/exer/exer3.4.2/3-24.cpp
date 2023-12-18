#include <iostream>
#include <string>
#include <vector>

using std::cin; using std::cout;
using std::endl;
using std::string; 
using std::vector;

int main() 
{
	vector<int> nums;
	int input;
	while (cin >> input) {
		nums.push_back(input);
	}
	for (auto head = nums.cbegin(), 
		last = nums.cend() - 1;
		head <= last;
		++head, --last) {
		cout << *head + *last << " ";
	} 
	cout << endl;

	return 0;
}
