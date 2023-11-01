#include <iostream>
#include <string>
#include <vector>

using std::cin; using std::cout;
using std::endl;
using std::string; 
using std::vector;

void print_vector(const vector<int> &vecs); 

int main() 
{
	const vector<int> nums = {1, 2, 3, 4, 5, 6};
	print_vector(nums);

	return 0;
}

void print_vector(const vector<int> &vecs) 
{
	if (vecs.size() == 1)
		cout << vecs[0] << endl;
	else {
		cout << vecs[0] << endl;
		vector<int> tmp;
		for (size_t i = 1; i != vecs.size(); ++i)
			tmp.push_back(vecs[i]);
		print_vector(tmp);
	}
}
