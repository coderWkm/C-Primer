#include <iostream>
#include <string>
#include "Sales_data.h"

using std::cin; using std::cout; using std::endl;
using std::string;
using std::istream; using std::ostream;


int main()
{
	Sales_data total(cin);
	if (!total.book_name.empty()) {	
		Sales_data trans(cin);
		while (1) {
			Sales_data trans(cin);
			if (total.isbn() == trans.isbn()) {
				total.combine(trans);
			}
			else {
				print(cout, total) << endl;
				total = trans;
			}
		}
	}
	else {
		std::cerr << "no data!" << endl;
	}

	return 0;
}

