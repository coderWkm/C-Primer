#include <iostream>
#include <map>
#include <list>
#include <string>

int main()
{
    std::map<std::string, std::list<int>> word_line{
        {"abandon", {1, 2, 3}},
        {"band", {4, 5, 6}}
    };
    std::cout << word_line.size() << "个单词：" << std::endl;
    for (auto &word:word_line) {
        std::cout << word.first << "出现在：";
        for (auto citer = word.second.cbegin(); citer != word.second.cend(); ++citer)
            std::cout << *citer << "、";
        std::cout << "页" << std::endl;
    }
    
    return 0;
}
