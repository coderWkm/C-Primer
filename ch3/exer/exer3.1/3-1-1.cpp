#include <iostream>
using std::cout; using std::cin;
using std::endl;

int main()
{
	int left, right;
	cout << "Please input two numbers" 
		  << "(left and right):"
		  << endl;
	cin >> left >> right;
	
	int i = left;
	while (i <= right) {
		cout << i << endl;
		++i;
	}

	return 0;
}
