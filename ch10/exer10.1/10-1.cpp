#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <string>

int main()
{
    std::vector<int> ivec{1, 1, 2, 2, 2, 3, 3, 3, 3, 3, 5, };
    std::cout << count(ivec.cbegin(), ivec.cend(), 3) << std::endl;
    std::cout << count(ivec.cbegin(), ivec.cend(), 6) << std::endl; // 6 不存在，返回0

    std::list<std::string> strs{"aaa", "aaa", "aaa", "aab", "aaac", "aaac", "wkm"};
    std::cout << count(strs.cbegin(), strs.cend(), "aaa") << std::endl; // 3
    std::cout << count(strs.cbegin(), strs.cend(), "abba") << std::endl; // 0
    return 0;
}
