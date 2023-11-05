#include <iostream>
#include <vector>
#include <list>

int main()
{
    std::vector<int> nums1{0, 1, 2, 3};
    std::vector<int> nums2{0, 1};
    std::vector<int> nums3{0, 1, 2, 3};
    std::vector<int> nums4{0, 1, 4, 3};

    std::cout << (( nums1 > nums2 ) ? ">" : "<") << std::endl;
    std::cout << (( nums1 == nums3 ) ? "==" : "!=") << std::endl;
    std::cout << (( nums1 > nums4 ) ? ">" : "<") << std::endl;

    return 0;
}
