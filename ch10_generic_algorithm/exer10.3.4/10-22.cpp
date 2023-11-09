#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
using namespace std::placeholders;
bool longer_than_length(const std::string &s, 
                        std::string::size_type length)
{
    return s.size() > length;
}

int main()
{
    std::vector<std::string> words{
        "thethe", "quick", "red", "fox", "jumps",
        "overover", "the", "slowwe", "redreder", "turtle"
    };
    std::string::size_type length;
    std::cout << "输入你想统计的长度：";
    std::cin >> length;
    int cnt = std::count_if(words.cbegin(), words.cend(), 
                            std::bind(longer_than_length, _1, length));
    std::cout << "有多少单词超过"  << length << ": "
              << cnt << std::endl;
    
    return 0;
}
