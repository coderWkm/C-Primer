#include <iostream>
#include <string>
#include <vector>

using std::cin; using std::cout;
using std::endl;
using std::string; 
using std::vector;

int get_sum(int a, int b) { return a + b;}
int get_diff(int a, int b) { return a - b;}
int get_product(int a, int b) { return a * b;}
int get_quotient(int a, int b) { return a / b;}

int main() 
{
	//1. 直接声明
	cout << endl;
	cout << "1.直接声明：" << endl;
	vector<int(*)(int, int)> PF_array;
	int (*pf1)(int, int) = get_sum;
	int (*pf2)(int, int) = get_diff;
	int (*pf3)(int, int) = get_product;
	int (*pf4)(int, int) = get_quotient;
	PF_array.push_back(pf1);
	PF_array.push_back(pf2);
	PF_array.push_back(pf3);
	PF_array.push_back(pf4);
	cout << (*PF_array[0])(20, 10) << endl;  // 30
	cout << (*PF_array[1])(20, 10) << endl;  // 10
	cout << (*PF_array[2])(20, 10) << endl;  // 200
	cout << (*PF_array[3])(20, 10) << endl;  // 2


	//2. using
	cout << endl;
	cout << "2, 使用using：" << endl;
	using PF2 = int(*)(int, int);
	vector<PF2> PF_array2;
	PF2 pf5 = get_sum, pf6 = get_diff, pf7 = get_product, pf8 = get_quotient;
	PF_array2.push_back(pf5);
	PF_array2.push_back(pf6);
	PF_array2.push_back(pf7);
	PF_array2.push_back(pf8);
	cout << (*PF_array2[0])(20, 10) << endl;// 30
	cout << (*PF_array2[1])(20, 10) << endl;// 10
	cout << (*PF_array2[2])(20, 10) << endl;// 200
	cout << (*PF_array2[3])(20, 10) << endl;// 2

	//3. typedef
	cout << endl;
	cout << "3. typedef：" << endl;
	typedef int (*PF3)(int, int);
	vector<PF3> PF_array3;
	PF3 pf31 = get_sum;
	PF3 pf32 = get_diff;
	PF3 pf33 = get_product;
	PF3 pf34 = get_quotient;
	PF_array3.push_back(pf31);
	PF_array3.push_back(pf32);
	PF_array3.push_back(pf33);
	PF_array3.push_back(pf34);
	cout << (*PF_array3[0])(20, 10) << endl;
	cout << (*PF_array3[1])(20, 10) << endl;
	cout << (*PF_array3[2])(20, 10) << endl;
	cout << (*PF_array3[3])(20, 10) << endl;

	//4. typedef+decltype
	cout << endl;
	cout << "4. typedef + decltype: " << endl;
	typedef decltype(get_sum) *PF4; 
	vector<PF4> PF_array4;
	PF4 pf41 = get_sum;
	PF4 pf42 = get_diff;
	PF4 pf43 = get_product;
	PF4 pf44 = get_quotient;
	PF_array4.push_back(pf41);
	PF_array4.push_back(pf42);
	PF_array4.push_back(pf43);
	PF_array4.push_back(pf44);
	cout << (*PF_array4[0])(20, 10) << endl;
	cout << (*PF_array4[1])(20, 10) << endl;
	cout << (*PF_array4[2])(20, 10) << endl;
	cout << (*PF_array4[3])(20, 10) << endl;
	
	
	return 0;
}
