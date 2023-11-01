#include <iostream>
#include <string>
#include <vector>
#include "Sales_data.h"

using std::cin; using std::cout;
using std::endl;
using std::string; 
using std::vector;

int main() 
{
	Sales_data s1;
	cout << endl;

	Sales_data s2(cin);
	cout << endl;
	Sales_data s3("aaaa");
	cout << endl;
	Sales_data s4("bbbb", 1, 1.0);
	
	return 0;
}
