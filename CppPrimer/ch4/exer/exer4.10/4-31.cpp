#include <iostream>
#include <string>
#include <vector>

using std::cin; using std::cout;
using std::endl;
using std::string; 
using std::vector;

int main() 
{
	vector<int> ivec(5, 0);
	vector<int>::size_type cnt = ivec.size();
	/*
	for (vector<int>::size_type ix = 0; ix != ivec.size(); ++ix, --cnt) {
		ivec[ix] = cnt;
		cout << ivec[ix] << " ";
	}
	cout << endl;
	*/

	for (vector<int>::size_type ix = 0; ix != ivec.size(); ix++, cnt--) {
		ivec[ix] = cnt;
		cout << ivec[ix] << " ";
	}
	cout << endl;
	return 0;
}
