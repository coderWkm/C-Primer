#include <iostream>
#include <string>
#include <vector>

using std::cin; using std::cout;
using std::endl;
using std::string; 
using std::vector;

int main() 
{
	int nums[10], copy[10];

	for (int i = 0;i < 10; ++i) {
		nums[i] = i;
		copy[i] = nums[i];
	}
	for(auto i : copy)
		cout << i << " ";
	cout << endl;

	cout << "****************************" << endl;

	vector<int> source(10);
	int counter = 0;
	for (auto iter = source.begin(); iter != source.end();
			iter++) {
		*iter = counter++;
	}
	vector<int> dest = source;

	for (auto value : dest)
		cout << value << " ";
	cout << endl;

	
		

	return 0;
}
