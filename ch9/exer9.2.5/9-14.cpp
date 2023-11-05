#include <iostream>
#include <list>
#include <string>
#include <vector>

int main()
{
    std::list<char*> c_strs = {"aaa", "bbb", "ccc"};
    std::vector<std::string> strings;
    strings.assign(c_strs.cbegin(), c_strs.cend());
    for (int i = 0; i != 3; ++i)
        std::cout << strings[i] << std::endl;
    
    return 0;
}
