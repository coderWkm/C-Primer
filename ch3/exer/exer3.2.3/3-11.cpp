#include <iostream>
#include <string>
#include <typeinfo>

using namespace std; 

int main() 
{
	const string s = "Keep out!";
    for (auto &c : s) {
        // 其他对 c 的操作
    }	
	return 0;
}
