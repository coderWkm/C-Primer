#include <iostream>
#include <map>
#include <string>
#include <vector>

int main()
{
    std::multimap<std::string, std::string> authors{
        {"wkm", "aaa"}, 
        {"yyy", "bbb"},
        {"mm", "999"},
        {"wkm", "ccc"}
    };
    auto num = authors.erase(authors.find("wkm"));
    std::cout << "authors size: " << authors.size() << ": ";
    for (const auto &item:authors)
        std::cout << item.first << " " << item.second << std::endl;
    
    return 0;
}
