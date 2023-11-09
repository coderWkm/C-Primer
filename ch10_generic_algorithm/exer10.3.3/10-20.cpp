#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

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
                            [length](const std::string &word)
                            {if (word.size() > length) return true; else return false;});
    std::cout << "有多少单词超过"  << length << ": "
              << cnt << std::endl;

    return 0;
}
