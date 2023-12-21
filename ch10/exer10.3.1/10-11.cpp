#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
bool isShorter(const std::string &s1, const std::string &s2);
void elimDups(std::vector<std::string> &words);

int main()
{
    std::vector<std::string> words = {
        //"the", "quick", "red", "fox", "jumps",
        //"over", "the", "slow", "red", "turtle"
        "asjfiqw", "aaaa", "AAAA", "aaaa", "ASDFKW"
    };
    elimDups(words);
        
    return 0;
}

bool isShorter(const std::string &s1, const std::string &s2)
{
    return s1.size() < s2.size();
}

void elimDups(std::vector<std::string> &words)
{
    // 先用字典排序，便于用unique查找单词
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
    words.erase(last, words.end());
    std::cout << "erase后，大小是：" << words.size() << std::endl;  
    for (auto iter = words.cbegin(); iter != words.cend(); ++iter)
        std::cout << *iter << " ";
    std::cout << std::endl;

    // 再用stable
    std::stable_sort(words.begin(), words.end(), isShorter);
    std::cout << "经过stable排序：" << std::endl;
    for (auto iter = words.cbegin(); iter != words.cend(); ++iter)
        std::cout << *iter << " ";
    std::cout << words.size() << std::endl;

}