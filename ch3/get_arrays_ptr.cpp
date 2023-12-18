#include <iostream>
#include <string>
#include <vector>
#include <iterator>

using std::cin; using std::cout;
using std::endl;
using std::string; 
using std::vector;
using std::begin; using std::end;

// iterator中的begin、end

int main() 
{
	int ia[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int *head = begin(ia);
	int *tail = end(ia);

	cout << "head: " << head << ", ";
	cout << *head << endl;
	cout << "tail: " << tail << ", ";
	cout << "tail - 1" << --tail << ", ";
	cout << *tail << endl;

	return 0;
}
