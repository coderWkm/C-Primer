#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    std::vector<int> nums{1, 2, 3, 4, 5};    
    auto res = find(nums.cbegin(), nums.cend(), 6);
    std::cout << (res == nums.cend() ? "3未找到" : "找到了") << std::endl;
    std::cout << *res << std::endl;
    
    return 0;
}
