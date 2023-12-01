#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <string>
using std::placeholders::_1;
int main()
{
    std::vector<std::string> strs{
        "pooth", "pooth", "werqw"
    };
    auto iter = std::find_if(strs.begin(), strs.end(), 
                        std::bind(std::not_equal_to<std::string>(), _1, "pooth"));
    std::cout << *iter << std::endl;

    std::vector<int> nums{
        1, 2, 3, 10000,
        500, (int)3e4, 52424
    };
    std::cout << std::count_if(nums.cbegin(), nums.cend(), 
                    std::bind(std::greater<int>(), _1, 1024)) 
              << std::endl;
    
    std::transform(nums.begin(), nums.end(), nums.begin(),
                    std::bind(std::multiplies<int>(), _1, 2));
    for (const auto &value : nums)
        std::cout << value << " ";
    return 0;
}
