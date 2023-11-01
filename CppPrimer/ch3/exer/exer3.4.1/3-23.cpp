#include <iostream>
#include <string>
#include <vector>

using std::cin; using std::cout;
using std::endl;
using std::string; 
using std::vector;

int main() 
{
	vector<int> nums(10, 1);
	for (vector<int>::iterator iter = nums.begin();
		iter != nums.end();
		++iter) {
		*iter *= 2;	
	}

	for (vector<int>::const_iterator citer = nums.cbegin();
		citer != nums.cend();
		++citer)
		cout << *citer << " ";
	cout << endl;

	return 0;
}
