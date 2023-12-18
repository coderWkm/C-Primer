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
	vector<int> nums;

	while (cin >> input)
		nums.push_back(input);
	
	cout << "相邻两数的和：" << endl;
	for (vector<int>::size_type i = 0; 
		i != nums.size() - 1; ++i) {
			cout << nums[i] + nums[i + 1] << " ";
		}
	cout << endl;

	cout << "对称位置两数的和：" << endl;
	for (vector<int>::size_type i = 0, j = nums.size() - 1;
			i <= j; ++i, --j)
			cout << nums[i] + nums[j] << " ";
	cout << endl;
	return 0;
}
