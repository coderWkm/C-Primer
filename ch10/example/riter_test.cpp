#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int main()
{
    std::vector<int> nums{1,2,3};
    std::ostream_iterator<int> output(std::cout, " ");
    copy(nums.crbegin(), nums.crend(), output); // 3 2 1
    
    return 0;
}
