#include <iostream>
#include <forward_list>
//P313下forware_list测试

int main()
{
    std::forward_list<int> fd_list{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::forward_list<int>::iterator prev = fd_list.before_begin(),
                                     cur = fd_list.begin();
    while (cur != fd_list.end()) {
        if (*cur % 2) {
            cur = fd_list.erase_after(prev);
        }
        else {
            prev = cur;
            ++cur;
        }
    }
    std::cout << "去除奇数后：" << std::endl;
    for (auto iter = fd_list.cbegin(); iter != fd_list.cend(); ++iter)
        std::cout << *iter << " ";

    return 0;
}
