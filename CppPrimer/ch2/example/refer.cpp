#include <iostream>
// p45-p46上，关于引用的绑定结果输出测试

int main() 
{
	int ival = 1024;
	int &refVal = ival;
	std::cout << "refVal: " << refVal << std::endl;
	std::cout << std::endl;

	refVal = 2;
	std::cout << "给refVal赋值2后：" << std::endl;
	std::cout << "ival: " << ival << std::endl;
	std::cout << "refVal: " << refVal << std::endl;
	std::cout << std::endl;

	int &refVal2 = refVal;
	std::cout << "refVal2绑定到refVal后：" << std::endl;
	std::cout << "refVal2:" << refVal2 << std::endl;
	std::cout << std::endl;

	int i = refVal2;
	std::cout << "i赋值位refVal2后：" << std::endl;
	std::cout << "i: " << i << std::endl;
	std::cout << std::endl;

	refVal2 = 10;
	std::cout << "修改refVal2的值为10：" << std::endl;
	std::cout << "ival: " << ival << std::endl;
	std::cout << "refVal: " << refVal << std::endl;
	std::cout << "refVal2:" << refVal2 << std::endl;
	std::cout << "i: " << i << std::endl;
	std::cout << std::endl;

	return 0;	
}
