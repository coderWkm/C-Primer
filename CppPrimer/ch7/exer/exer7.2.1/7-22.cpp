#include <iostream>
#include "Person.h"

using std::cin; using std::cout;
using std::endl;

int main() 
{
	Person p("wkmyyy", "China");
	cout << "你的信息：";
	print_info(cout, p) << endl;
	return 0;
}

