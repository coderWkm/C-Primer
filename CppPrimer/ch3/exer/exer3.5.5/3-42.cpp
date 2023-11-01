#include <iostream>
#include <string>
#include <vector>

using std::cin; using std::cout;
using std::endl;
using std::string; 
using std::vector;

int main() 
{
	//首先明确不允许使用vector初始化数组
	vector<int> nums(5, 1);
	int nums_copy[5];

	// 1. 访问vector下标
	cout << "下标访问：" << endl;
	for (int i = 0; i < 5; ++i) {
		nums_copy[i] = nums[i];
		cout << nums_copy[i] << " ";
	} 
	cout << endl;

	// 2. 迭代器
	cout << "迭代器：" << endl;
	int j = 0;
	for (auto cbeg = nums.cbegin(); cbeg != nums.cend();
		++cbeg) {
		nums_copy[j] = *cbeg;
		cout << nums_copy[j++] << " ";
	}
	cout << endl;
	return 0;
}
