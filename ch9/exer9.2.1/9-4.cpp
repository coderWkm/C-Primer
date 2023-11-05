#include <iostream>
#include <vector>
#include <iterator>

using const_iter = std::vector<int>::const_iterator;
const_iter find_value(const_iter cbeg, const_iter cend, int value);

int main()
{
    std::vector<int> nums{0, 1, 2, 3, 4, 5};
    const_iter flag = nums.cend();
    int choice = 0;
    while (std::cin >> choice) {
        if (find_value(nums.cbegin(), nums.cend(), choice) != flag)
            std::cout << choice << "exists!" << std::endl;
        else
            std::cout << "no" << std::endl;
    }
    return 0;
}

const_iter find_value(const_iter cbeg, const_iter cend, int value)
{
    while (cbeg != cend) {
        if (*cbeg == value)
            return cbeg;
        ++cbeg;
    }
    return cend;
}