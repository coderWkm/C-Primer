#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <functional>
using namespace std::placeholders;

bool isShort(const std::string &s1, const std::string &s2)
{   
    return (s1.size() < s2.size() ? true : false); 
}
void print(const std::vector<std::string> &words)
{
    for (auto iter = words.cbegin(); iter != words.cend(); ++iter)
        std::cout << *iter << " ";
    std::cout << std::endl;
}

int main()
{
    std::vector<std::string> words{
        "aaa", "bbbb", "Cc", "waeoprkfjdslk",
        "z;slq[03-]", "his", "we"
    };    
    std::cout << "排序前：";
    print(words);
    std::cout << "排序后：";
    std::sort(words.begin(), words.end(), isShort);
    print(words);
    std::cout << "********************************" << std::endl;
    std::sort(words.begin(), words.end(), bind(isShort, _2, _1));
    print(words);
    return 0;
}
