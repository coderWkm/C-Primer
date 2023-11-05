#include <iostream>
#include <deque>
#include <string>

int main()
{
    std::deque<std::string> strs_deque;
    std::string input;
    std::deque<std::string>::iterator iter = strs_deque.begin();
    while (std::cin >> input) {
        iter = strs_deque.emplace(iter, input); // emplace返回指向新添加元素的迭代器，同insert；
    }
    for (iter = strs_deque.begin(); iter != strs_deque.end(); ++iter)
        std::cout << *iter << " ";
    std::cout << std::endl;
    
    return 0;
}
