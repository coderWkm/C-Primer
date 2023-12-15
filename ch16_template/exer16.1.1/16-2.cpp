#include <iostream>
#include <vector>
#include <string>

template <typename T>
int compare(const T &v1, const T &v2)
{
    if (v1 < v2) return -1;
    if (v2 < v1) return 1;
    return 0;
}

int main()
{
    std::cout << "int 1 和 0：" << compare(1, 0) << std::endl;
    std::vector<int> nums1{1, 2, 3}, nums2{4, 5, 6};
    std::cout << "vector 1, 2, 3和 4, 5, 6：" << compare(nums1, nums2) << std::endl;
    std::cout << "string: abc和 acc: " << compare(std::string("abc"), std::string("acc")) << std::endl;

    return 0;
}
