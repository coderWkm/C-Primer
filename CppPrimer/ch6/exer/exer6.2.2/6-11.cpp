#include <iostream>
#include <string>
#include <vector>

using std::cin; using std::cout;
using std::endl;
using std::string; 
using std::vector;

void reset(int &input);

int main() 
{
	int i = 100;
	reset(i);

	return 0;
}

void reset(int &input)
{
	cout << "Before modifying, input: "
		 << input << endl;
	input = 0;
	cout << "After modifying, input: "
		 << input << endl;

}
