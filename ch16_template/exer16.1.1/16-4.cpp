#include <iostream>
#include <list>
#include <string>
#include <vector>

template <typename T, typename V>
T my_find(T cbeg, T cend, const V &val)
{
    while (cbeg != cend) {
        if ( *cbeg == val)
            return cbeg;
        ++cbeg;
    }
    return cend;
}

int main()
{
    std::vector<int> nums{1, 2, 3, 4, 5};
    auto res = my_find(nums.begin(), nums.end(), 3);
    if (res != nums.end())
        std::cout << "找到了" << *res 
                  << ", 在第" << res - nums.begin() << "个位置"
                  << std::endl;
    else 
        std::cout << "未找到" << std::endl;
     
    std::list<std::string> str_list{"abc", "def", "ghad", "lqwo"};
    auto obj = my_find(str_list.begin(), str_list.end(), "aaaa");
    if (obj != str_list.end())
        std::cout << "找到了" << *obj << std::endl;
    else 
        std::cout << "未找到" << std::endl;

    return 0;
}
