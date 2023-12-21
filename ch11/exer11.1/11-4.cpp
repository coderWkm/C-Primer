#include <iostream>
#include <map>
#include <string>

std::string &str_convert(std::string &s)
{
    // 为什么必须p != size()会段错误
    for (std::string::size_type p = 0; p < s.size(); ++p) {
        if (s[p] >= 'A' && s[p] <= 'Z')
            s[p] += ('a' - 'A');
        else if (s[p] == ',' || s[p] == '.')
            s.erase(p, 1);
    }
    return s;
}

int main()
{
    std::map<std::string, size_t> words;
    std::string input;
    while (std::cin >> input) {
        ++words[str_convert(input)];
    }   
    for (const auto &item:words)
        std::cout << item.first << " occurs " << item.second
                  << (item.second > 1 ? "times" : "time")
                  << std::endl;
    return 0;
}
