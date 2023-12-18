#include <iostream>
#include <string>
#include <vector>

using std::cin; using std::cout;
using std::endl;
using std::string; 
using std::vector;

void swap_ptr(int **p1, int **p2);

int main() 
{
	int a = 1, b = 2;
	int *pa = &a, *pb = &b;
	cout << "交换之前：" << endl;
	cout << "a地址：" << pa 
		 << ", b地址：" << pb << endl;
	swap_ptr(&pa, &pb);
	cout << "交换之后：" << endl;
	cout << "a地址：" << pa
		 << ", b地址：" << pb << endl;

	return 0;
}

void swap_ptr(int **p1, int **p2)
{
	int *tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
