#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    std::vector<int> nums{1, 2, 3, 4, 5};
    for (auto iter = nums.cbegin(); iter != nums.cend(); ++iter)
        std::cout << *iter << " ";
    std::cout << std::endl;
    fill_n(nums.begin(), nums.size(), 0);
    for (auto iter = nums.cbegin(); iter != nums.cend(); ++iter)
        std::cout << *iter << " ";

    return 0;
}
