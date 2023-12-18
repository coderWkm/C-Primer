#include <iostream>
#include <string>
#include <vector>

using std::cin; using std::cout;
using std::endl;
using std::string; 
using std::vector;

int main() 
{
	constexpr size_t sz = 5;
	int arr[sz] = {1, 2, 3, 4, 5};
	int *ip = arr;
	cout << "Address: "<< ip << ", value: " << *ip << endl;

	int *ip4 = ip + 4;
	cout << "Address: "<< ip4 << ", value: " << *ip4 << endl;

	return 0;
}
