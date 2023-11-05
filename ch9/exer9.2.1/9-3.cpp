#include <iostream>
#include <vector>
#include <iterator>

//using std::vector<int>::const_iterator const_iter;
bool find_value(std::vector<int>::const_iterator cbeg,
                 std::vector<int>::const_iterator cend, int value);

int main()
{
    std::vector<int> nums{0, 1, 2, 3, 4, 5};
    if (find_value(nums.cbegin(), nums.cend(), 6))
        std::cout << "yes" << std::endl;
    else
        std::cout << "no" << std::endl;
    return 0;
}

bool find_value(std::vector<int>::const_iterator cbeg, 
                std::vector<int>::const_iterator cend, int value)
{
    while (cbeg != cend) {
        if (*cbeg == value)
            return true;
        ++cbeg;
    }
    return false;
}