#include <iostream>
#include <vector>
void print_info(const std::vector<int> &values);

int main()
{
    std::vector<int> nums(25, 1);
    print_info(nums);

    nums.resize(100);
    print_info(nums);

    nums.resize(10);
    print_info(nums);
    
    return 0;
}

void print_info(const std::vector<int> &values)
{
    std::cout << "有" << values.size() << "个元素：";
    for (auto item : values)
        std::cout << item << " ";
    std::cout << std::endl;
    
}