#include <iostream>
#include <string>
#include <vector>

using std::cin; using std::cout;
using std::endl;
using std::string; 
using std::vector;
using std::begin; using std::end;

int main() 
{
	int a[] = {0, 1, 2};
	int b[] = {0, 1, 2};

	int length_a = 0, length_b = 0;
	int *ptra, *ptrb;
	for (ptra = begin(a), ptrb = begin(b);
		ptra != end(a) && ptrb != end(b);
		++ptra, ++ptrb) {
		++length_a;
		++length_b;
	}
	if (ptra != end(a)) {
		while (ptra != end(a)) {
			++length_a;
			++ptra;
		}
	}
	else if (ptrb != end(b)) {
		while (ptrb != end(b)) {
			++length_b;
			++ptrb;
		}
	}
	if (length_a != length_b) {
		cout << "a数组长度:" << length_a;
		cout << "！=  b数组长度: " << length_b << endl;
		return -1;
	}
	for (int i = 0; i < length_a; ++i) {
		if (a[i] != b[i]) {
			cout << "在索引" << i << "处元素不等：" << endl;
			cout << "a: " << a[i] << ", ";
			cout << "b: " << b[i] << endl;
			return -1;
		}
	}
	cout << "数组相等！" << endl;
	cout << "!!!!!!!!!!!!!!" << endl;
	vector<int> nums1(5, 0);
	vector<int> nums2(5, 0);
	if (nums1 == nums2)
		cout << "相等" << endl;
	else
		cout << "不相等" << endl;

	return 0;
}
