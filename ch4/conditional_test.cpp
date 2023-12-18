#include <iostream>
#include <string>
#include <vector>

using std::cin; using std::cout;
using std::endl;
using std::string; 
using std::vector;

int main() 
{
	int grade = 70;
	cout << ((grade < 60) ? "low" : "high") << endl;
	cout << (grade < 60) ? "low" : "high" << endl;
	//cout << grade < 60 ? "low" : "high" << endl;
	cout << (grade < 60 ? "low" : "high") << endl;

	return 0;
}
