#include <iostream>
#include <vector>

int main()
{
    std::vector<int> nums{1, 2, 3, 4, 5};
    for (auto riter = nums.crbegin(); riter != nums.crend(); ++riter)
        std::cout << *riter << " ";
    std::cout << std::endl;

    // 10-35
    for (auto citer = nums.cend() - 1; citer != nums.cbegin(); --citer)
        std::cout << *citer << " ";
    std::cout << *nums.cbegin() << std::endl;
    return 0;
}
