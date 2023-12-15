#include <iostream>
#include <vector>

template <typename It>
auto fcn3(It beg, It end) -> decltype(*beg + 0)
{
    // ...
    return *beg; 
}

int main()
{
    std::vector<int> nums{1, 2, 3};
    auto res = fcn3(nums.begin(), nums.end());  
    /**
     * 上述res类型是int
     * 编译器推断fcn3在此处的定义：返回值是int
     * auto fcn3<std::vector<int>::iterator>(std::vector<int>::iterator beg, std::vector<int>::iterator end)->int
     * */      
    return 0;
}
