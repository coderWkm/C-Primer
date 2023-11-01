#include <iostream>
#include <string>
#include <vector>

using std::cin; using std::cout;
using std::endl;
using std::string; 
using std::vector;

int main() 
{
	cout << "整型：" << endl; 
	cout << "bool's size: " << sizeof(bool) << endl;
	cout << "char's size: " << sizeof(char) << endl;
	cout << "unsigned short's size: " << sizeof(unsigned short) << endl;
	cout << "short's size: " << sizeof(short) << endl;
	cout << "unsigned int's size: " << sizeof(unsigned int) << endl;
	cout << "int's size: " << sizeof(int) << endl;
	cout << "unsigned long's size: " << sizeof(unsigned long) << endl;
	cout << "long's size: " << sizeof(long) << endl;
	cout << "unsigned long long's size: " << sizeof(unsigned long long) << endl;
	cout << "long long's size: " << sizeof(long long) << endl;
	
	cout << endl << "浮点型：" << endl; 
	cout << "float's size: " << sizeof(float) << endl;
	cout << "double's size: " << sizeof(double) << endl;
	
	cout << endl << "指针：" << endl; 
	cout << "bool's size: " << sizeof(bool*) << endl;
	cout << "char's size: " << sizeof(char*) << endl;
	cout << "unsigned short's size: " << sizeof(unsigned short*) << endl;
	cout << "short's size: " << sizeof(short*) << endl;
	cout << "unsigned int's size: " << sizeof(unsigned int*) << endl;
	cout << "int's size: " << sizeof(int*) << endl;
	cout << "unsigned long's size: " << sizeof(unsigned long*) << endl;
	cout << "long's size: " << sizeof(long*) << endl;
	cout << "unsigned long long's size: " << sizeof(unsigned long long*) << endl;
	cout << "long long's size: " << sizeof(long long*) << endl;
	cout << "float's size: " << sizeof(float*) << endl;
	cout << "double's size: " << sizeof(double*) << endl;
	

	
	return 0;
}
