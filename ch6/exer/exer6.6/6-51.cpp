#include <iostream>
#include <string>
#include <vector>

using std::cin; using std::cout;
using std::endl;
using std::string; 
using std::vector;

void f() {cout << "无参函数" << endl;}
void f(int a) {cout << "一个int" << endl;}
void f(int a, int b) {cout << "两个int" << endl;}
void f(double a, double b) {cout << "两个double" << endl;}

int main() 
{
    // f(2.56, 42);  // 提示有二义性
	f(42);
	f(42, 0);
	f(2.56, 3.14);

	return 0;
}
