#include <iostream>
#include <string>
#include <vector>

using std::cin; using std::cout;
using std::endl;
using std::string; 
using std::vector;

int &get(int *arry, int index) {return arry[index];}

int main() 
{
	int ia[10];
	for (int i = 0; i != 10; ++i) {
		get(ia, i) = i;
		cout << "ia[" << i << "]: " 
			 << ia[i] << endl;
	}

	return 0;
}
