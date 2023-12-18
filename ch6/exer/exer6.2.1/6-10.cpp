#include <iostream>
#include <string>
#include <vector>

using std::cin; using std::cout;
using std::endl;
using std::string; 
using std::vector;

void swap(int *p_num1, int *p_num2);

int main() 
{
	int a = 10, b = 20;
	cout << "a的地址: " << &a
		 << ", a: " << a << endl;
	cout << "b的地址: " << &b
		 << ", b: " << b << endl;
	swap(&a, &b);
	cout << "交换后:" << endl; 
	cout << "a的地址: " << &a
		 << ", a: " << a << endl;
	cout << "b的地址: " << &b
		 << ", b: " << b << endl;

	return 0;
}

void swap(int *p_num1, int *p_num2) 
{
	int tmp = *p_num1;
	*p_num1 = *p_num2;
	*p_num2 = tmp;
}
