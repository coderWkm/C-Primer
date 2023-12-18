#include <iostream>
#include <string>
#include <vector>

using std::cin; using std::cout;
using std::endl;
using std::string; 
using std::vector;

int main() 
{
	

	return 0;
}

bool str_subrange(const string &str1, const string &str2)
{
	if (str1.size() == str2.size())
		return str1 == str2;
	auto size = (str1.size() < str2.size()) 
				? str1.size() : str2.size();
	for (decltype(size) i = 0; i != size; ++i) {
		if (str1[i] != str2[i])
			return;
	}
					
}
/*
6-30.cpp: In function ‘bool str_subrange(const string&, const string&)’:
6-30.cpp:25:4: error: return-statement with no value, in function returning ‘bool’ [-fpermissive]
   25 |    return;
      |    ^~~~~~
*/
