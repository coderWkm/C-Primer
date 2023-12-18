#include <iostream>
#include <string>
#include <vector>

using std::cin; using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() 
{
	vector<int> v1;
	vector<int> v2(10);
	vector<int> v3(10, 42);
	vector<int> v4{10};
	vector<int> v5{10, 42};
	vector<string> v6{10};
	vector<string> v7{10, "hi"};

	cout << "v1's size: " << v1.size() << endl;
	cout << "v2's size: " << v2.size() << endl;
	cout << "v3's size: " << v3.size() << endl;
	cout << "v4's size: " << v4.size() << endl;
	cout << "v5's size: " << v5.size() << endl;
	cout << "v6's size: " << v6.size() << endl;
	cout << "v7's size: " << v7.size() << endl;

	if (!v1.empty())
	{
		for (auto value : v1)
			cout << value << " ";
		cout << endl;
	}
	if (!v2.empty())
	{
		for (auto value : v2)
			cout << value << " ";
		cout << endl;
	}
	if (!v3.empty())
	{
		for (auto value : v3)
			cout << value << " ";
		cout << endl;
	}
	if (!v4.empty())
	{
		for (auto value : v4)
			cout << value << " ";
		cout << endl;
	}
	if (!v5.empty())
	{
		for (auto value : v5)
			cout << value << " ";
		cout << endl;
	}
	if (!v6.empty())
	{
		for (auto value : v6)
			cout << value << " ";
		cout << endl;
	}
	if (!v7.empty())
	{
		for (auto value : v7)
			cout << value << " ";
		cout << endl;
	}
	


	return 0;
}
