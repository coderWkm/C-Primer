#include <iostream>
#include <vector>
void print(const std::vector<int> &nums);

int main()
{
    //1. 拷贝： = 或者（）
    std::cout << "1. 拷贝： = 或者（）:" << std::endl;
    std::vector<int> nums1;
    std::vector<int> nums3{0, 1, 2, 3};
    nums1 = nums3;
    print(nums1);
    std::vector<int> nums2(nums3);
    print(nums2);

    //2. 列表初始化{}/={}
    std::cout << "2.  列表初始化{}/={}:" << std::endl;
    std::vector<int> nums4{nums1};
    print(nums4);
    std::vector<int> nums5 = {nums1};
    print(nums5);

    //3. 迭代器指示范围
    std::cout << "3. 迭代器指示范围:" << std::endl;
    std::vector<int> nums6(nums1.cbegin(), nums1.cend());
    print(nums6);
    
    //4. seq(n)
    std::cout << "4. seq(n):" << std::endl;
    std::vector<int> seq(4);
    print(seq);

    //5. seq(n, t)
    std::cout << "5. seq(n, t):" << std::endl;
    std::vector<int> seq2(4, 4);
    print(seq2);

    return 0;
}

void print(const std::vector<int> &nums)
{
    for (auto iter = nums.cbegin(); iter != nums.cend(); ++iter)
        std::cout << *iter << " ";
    std::cout << std::endl;
}