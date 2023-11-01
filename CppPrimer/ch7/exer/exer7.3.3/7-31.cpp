#include <iostream>
#include <string>
#include <vector>

using std::cin; using std::cout;
using std::endl;
using std::string; 
using std::vector;

class A;
class B;

class A {
private:
	B *ptrB;
};
class B {
	A itemA;
};

int main() 
{

	return 0;
}
