#include <iostream>
#include <string>
#include <vector>

using std::cin; using std::cout;
using std::endl;
using std::string; 
using std::vector;

int main() 
{
	int nums[10];

	for (int i = 0;i < 10; ++i)
		nums[i] = i;
	
	for (auto value : nums)
		cout << value << " ";
	cout << endl;

	return 0;
}
