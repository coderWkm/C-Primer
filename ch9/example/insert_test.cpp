#include <iostream>
#include <list>
#include <string>

int main()
{
    std::list<std::string> word_list;
    std::string word;
    std::list<std::string>::iterator iter = word_list.begin();
    while (std::cin >> word)
        iter = word_list.insert(iter, word);
    for (iter = word_list.begin(); iter != word_list.end(); ++iter)
        std::cout << *iter << " ";

    return 0;
}
