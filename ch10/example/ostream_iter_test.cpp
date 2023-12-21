#include <iostream>
#include <vector>
#include <iterator>

int main()
{
    std::vector<int> nums{1, 2, 3, 4, 5};
    std::ostream_iterator<int> output(std::cout, " ");
    for (auto value : nums)
        *output++ = value;
    std::cout << "*********************" << std::endl;
    std::copy(nums.cbegin(), nums.cend(), output);
    
    return 0;
}
