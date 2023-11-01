#include <iostream>
#include <string>
#include <vector>
#include "Screen.h"

using std::cin; using std::cout;
using std::endl;
using std::string; 
using std::vector;

int main() 
{
	Screen myscreen(5, 5, 'X');
	myscreen.move(4, 0).set('#').display(cout);
	cout << "\n";
	myscreen.display(cout);
	cout << "\n";
	return 0;
}
