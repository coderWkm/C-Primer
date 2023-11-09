#include <iostream>
#include <list>
#include <algorithm>
#include <vector>
#include <iterator>
int main()
{
    std::vector<int> nums{0, 3, 6, 8, 2, 5, 9, 1, 4, 7};
    std::list<int> dest;
    std::vector<int>::reverse_iterator end = nums.rbegin() + 2; // 一开始+3,结果少了第7位置的值
    std::vector<int>::reverse_iterator begin = nums.rbegin() + 7;
    std::copy(end, begin, std::back_inserter(dest)); 
    for (auto value:dest)
        std::cout << value << " ";
    // 1 9 5 2 8 
    return 0;
}
