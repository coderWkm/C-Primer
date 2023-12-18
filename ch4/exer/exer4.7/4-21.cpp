#include <iostream>
#include <vector>

using std::cin; using std::cout;
using std::endl;
using std::vector;

int main() 
{
	vector<int> nums = {1, 2, 3, 4, 5};

	for (auto &value : nums) {
		if (value % 2) {
			value *= 2;
		}
		cout << value << " ";
	}
	cout << endl;

	return 0;
}
