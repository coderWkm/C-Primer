#include <iostream>
#include "Chapter6.h"

int fact(int num) 
{
	int res = 1;
	if (!num || num == 1)
		return res;
	else if (num > 1)
	{
		while (num > 1) {
			res *= num;
			--num;
		}
		return res;
	}
	else {
		std::cout << "输入有误，请输入>0的正整数！"
			 << std::endl;
		return -1;
	}
}
