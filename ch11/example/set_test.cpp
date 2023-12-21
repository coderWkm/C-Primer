#include <iostream>
#include <set>
#include <map>
#include <string>

int main()
{
    std::map<std::string, size_t> word_count;
    std::set<std::string> exclude = {
        "the", "but", "and", "or", "an", "a",
        "The", "But", "And", "Or", "An", "A"
    };
    std::string word;
    while (std::cin >> word) {
        if (exclude.find(word) == exclude.end()) {
            ++word_count[word];
        }
    }
    for (const auto &w : word_count) 
        std::cout << w.first << " occurs " << w.second   // 通过first、second分别访问key、value
                  << (w.second > 1 ? "times" : "time")
                  << std::endl;
    
    return 0;
}
