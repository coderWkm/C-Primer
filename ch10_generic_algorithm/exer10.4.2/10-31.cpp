#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>

int main()
{
    std::istream_iterator<int> in(std::cin), eof;
    std::vector<int> nums;
    while (in != eof)
        nums.push_back(*in++);
    std::sort(nums.begin(), nums.end());
    std::ostream_iterator<int> output(std::cout, " ");
    std::unique_copy(nums.cbegin(), nums.cend(), output);
    
    return 0;
}
