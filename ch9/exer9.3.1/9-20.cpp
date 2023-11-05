#include <iostream>
#include <list>
#include <deque>

int main()
{
    std::list<int> num_list{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::deque<int> odd, even;
    std::list<int>::const_iterator list_iter = num_list.cbegin();
    for (; list_iter != num_list.cend(); ++list_iter) {
        if (!(*list_iter % 2)) 
            even.insert(even.end(), *list_iter);
        else
            odd.insert(odd.end(), *list_iter);
    }

    // 打印
    std::cout << "奇数：" << std::endl;
    for (auto iter_odd = odd.cbegin(); iter_odd != odd.cend(); ++iter_odd)
        std::cout << *iter_odd << " ";
    std::cout << std::endl;
    std::cout << "偶数：" << std::endl;
    for (auto iter_even = even.cbegin(); iter_even != even.cend(); ++iter_even)
        std::cout << *iter_even << " ";
    std::cout << std::endl;
    
    return 0;
}
