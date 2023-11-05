#include <iostream>
#include <list>

int main()
{
    std::list<int> lst{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::list<int>::iterator iter = lst.begin();
    while (iter != lst.end()) {
        if (*iter % 2)
            iter = lst.erase(iter);
        else
            ++iter;
    }

    for (iter = lst.begin(); iter != lst.end(); ++iter)
        std::cout << *iter << " ";
    std::cout << std::endl;

    auto tmp = lst.begin();
    ++tmp;
    ++tmp;
    std::cout << "删除某一范围元素：" << std::endl;
    lst.erase(lst.begin(), tmp);
    for (iter = lst.begin(); iter != lst.end(); ++iter)
        std::cout << *iter << " ";
    std::cout << std::endl;

    std::cout << "删除全部元素：" << std::endl;
    lst.clear();
    std::cout << lst.size() << std::endl;

    return 0;
}
