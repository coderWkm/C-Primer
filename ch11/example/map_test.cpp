#include <iostream>
#include <map>
#include <string>

int main()
{
    std::map<std::string, size_t> word_count;
    std::string word;
    while (std::cin >> word) {
        ++word_count[word]; //下标访问map，只不过下标是key，这里的string
    }
    for (const auto &w : word_count) 
        std::cout << w.first << " occurs " << w.second   // 通过first、second分别访问key、value
                  << (w.second > 1 ? "times" : "time")
                  << std::endl;
    
    return 0;
}
