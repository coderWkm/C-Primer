#include <iostream>
#include <vector>
template <typename Container> 
void print(Container &nums) 
{ 
    using size_type = typename Container::size_type;
    //for (const auto &item : nums)
    for (size_type i = 0; i != nums.size(); ++i)
        std::cout << nums[i] << " ";
}

int main()
{
    std::vector<int> nums{1, 2, 3, 4, 5};
    print(nums);

    return 0;
}
