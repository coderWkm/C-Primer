#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

void elimDups(std::vector<std::string> &words);

int main()
{
    std::vector<std::string> texts{
        "the", "quick", "red", "fox", "jumps",
        "over", "the", "slow", "red", "turtle"
    };
    elimDups(texts);
    for (auto iter = texts.cbegin(); iter != texts.cend(); ++iter)
        std::cout << *iter << " ";
    std::cout << std::endl;
    
    return 0;
}
void elimDups(std::vector<std::string> &words)
{
    sort(words.begin(), words.end());
    std::cout << "经过排序后，大小是:" << words.size() << std::endl;
    for (auto iter = words.cbegin(); iter != words.cend(); ++iter)
        std::cout << *iter << " ";
    std::cout << std::endl;
    std::vector<std::string>::iterator last = unique(words.begin(), words.end());
    std::cout << "unique后，大小是：" << words.size() << std::endl;  
    for (auto iter = words.cbegin(); iter != words.cend(); ++iter)
        std::cout << *iter << " ";
    std::cout << std::endl;
    /*
    unique后，大小是：10
    fox jumps over quick red slow the turtle the   (最后一个是"")
    可以看出unique不改变原vector的大小
    */
    words.erase(last, words.end());
}