#include <iostream>
#include <string>
#include <vector>

using std::cin; using std::cout;
using std::endl;
using std::string; 
using std::vector;

class NoDefault {
public:
	NoDefault(int value): a(value) { }
	int a;
};

class C {
public:
	C(): no(0) { }
	// C() = default;
	NoDefault no;
};

int main() 
{
	C c;
	cout << c.no.a << endl;
	return 0;
}
