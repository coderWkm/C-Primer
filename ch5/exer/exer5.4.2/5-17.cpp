#include <iostream>
#include <string>
#include <vector>

using std::cin; using std::cout;
using std::endl;
using std::string; 
using std::vector;

int main() 
{
	int input;
	vector<int> nums1, nums2;
	cout << "输入第一组：" << endl;
	while (cin >> input && input != -1)
		nums1.push_back(input);
	cout << "第一组输入结束" << endl;

	cout << "输入第二组：" << endl;
	while (cin >> input && input != -1)
		nums2.push_back(input);
	cout << "第二组输入结束" << endl;
	
	int l1 = nums1.size(), l2 = nums2.size();
	if (l1 == l2) {
		cout << "两个数组一样长！";
		return -1;
	}
	else {
		int min_len = l1 < l2 ? l1 : l2;
		for (int i = 0; i != min_len; ++i) {
			if (nums1[i] != nums2[i]) {
				cout << "不存在前缀关系" << endl;
				return -1;
			}
		}
		cout << "存在前缀关系" << endl;
	}

	return 0;
}
