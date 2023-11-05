#include <iostream>
#include <list>

int main()
{
    std::list<int> lst{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::list<int> lst2{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::list<int> lst3{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::list<int>::iterator beg = lst.begin();
    //std::list<int>::iterator mid = lst.begin() + lst.size()/2;
    std::cout << "原数据：";
    for (auto iter = lst.begin(); iter != lst.end(); ++iter)
        std::cout << *iter << " ";
    std::cout << std::endl;
    
    std::cout << "erase(begin,begin)：";
    lst.erase(lst.begin(), lst.begin());
    for (auto iter = lst.begin(); iter != lst.end(); ++iter)
        std::cout << *iter << " ";
    std::cout << std::endl;

    std::cout << "erase(begin,end)：";
    lst2.erase(lst2.begin(), lst2.end());
    for (auto iter = lst2.begin(); iter != lst2.end(); ++iter)
        std::cout << *iter << " ";
    std::cout << std::endl;
    
    std::cout << "erase(end,end)：";
    lst3.erase(lst3.end(), lst3.end());
    for (auto iter = lst3.begin(); iter != lst3.end(); ++iter)
        std::cout << *iter << " ";
    std::cout << std::endl;

    return 0; 
}

/*
原数据：0 1 2 3 4 5 6 7 8 9 10 
erase(begin,begin)：0 1 2 3 4 5 6 7 8 9 10
erase(begin,end)：
erase(end,end)：0 1 2 3 4 5 6 7 8 9 10
*/