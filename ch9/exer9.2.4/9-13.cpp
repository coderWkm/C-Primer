#include <iostream>
#include <vector>
#include <list>
void print(const std::vector<double> &nums);

int main()
{
    std::list<int> source = {1, 2, 3, 4, 5};
    std::vector<int> source2 = {2, 4, 6, 8, 10};
    std::vector<double> dest1(source.cbegin(), source.cend());
    print(dest1);
    std::vector<double> dest2(source2.cbegin(), source2.cend());
    print(dest2);

    return 0;
}

void print(const std::vector<double> &nums)
{
    for (auto iter = nums.cbegin(); iter != nums.cend(); ++iter)
        std::cout << *iter << " ";
    std::cout << std::endl;
}