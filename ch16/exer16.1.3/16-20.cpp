#include <iostream>
#include <vector>
template <typename Container> 
void print(Container &nums) 
{ 
    //using const_iter = Container::const_iterator;
    for (auto citer = nums.cbegin(); citer != nums.cend(); ++citer)
        std::cout << *citer << " ";
}

int main()
{
    std::vector<int> nums{1, 2, 3, 4, 5};
    print(nums);

    return 0;
}
