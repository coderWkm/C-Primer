#include <iostream>
#include <vector>

using std::cin; using std::cout;
using std::endl;
using std::vector; 

int main() 
{
	int input;
	vector<int> nums;

	while (cin >> input) {
		nums.push_back(input);
	}
	for (auto value : nums)
		cout << value << " ";
	cout << endl;

	return 0;
}
