#include <iostream>
#include <vector>
#include <list>

int main()
{
    std::vector<int> nums1{0, 1, 2, 3};
    std::list<int> l1{0, 1, 2,3};

    std::vector<int> l1_copy(l1.cbegin(), l1.cend());

    if (l1_copy == nums1)
        std::cout << "==" << std::endl;
    else
        std::cout << "!=" << std::endl;

    return 0;
}
