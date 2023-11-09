#include <iostream>
#include <algorithm>
#include <list>

int main()
{
    std::list<int> ilist{1, 2, 3, 0, 20, 59, 33, 0 ,2};
    auto riter = std::find(ilist.crbegin(), ilist.crend(), 0);
    std::cout << "逆向找到的0的左侧元素："; 
    for (;riter != ilist.crend(); ++riter)
        std::cout << *riter << " ";
    std::cout << std::endl;

    auto iter = std::find(ilist.cbegin(), ilist.cend(), 0);
    std::cout << "正向找到的0的右侧元素：";
    for (;iter != ilist.cend(); ++iter)
        std::cout << *iter << " ";
    return 0;
}
