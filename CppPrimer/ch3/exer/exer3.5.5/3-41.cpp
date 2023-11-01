#include <iostream>
#include <string>
#include <vector>

using std::cin; using std::cout;
using std::endl;
using std::string; 
using std::vector;
using std::begin; using std::end;

int main() 
{
	int arr[] = {1, 2, 3, 4, 5};
	vector<int> arrcopy(begin(arr), end(arr));
	cout << "After copying: ";
	for (auto value : arrcopy)
		cout << value << " ";

	return 0;
}
