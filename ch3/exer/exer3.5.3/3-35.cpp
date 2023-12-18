#include <iostream>
#include <string>
#include <vector>

using std::cin; using std::cout;
using std::endl;
using std::string; 
using std::vector;
using std::end;

int main() 
{
	int nums[] = {1, 2, 3, 4, 5};

	for (int *ptr = nums; ptr != end(nums); ++ptr)
		*ptr = 0;
	for (auto value : nums)
		cout << value << " ";
	cout << endl;

	return 0;
}
