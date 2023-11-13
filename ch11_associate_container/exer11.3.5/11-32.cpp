#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <set>

int main()
{
    std::multimap<std::string, std::string> authors{
        {"alan", "DMA"}, {"pezy", "LeetCode"}, {"alan", "CLRS"},
        {"wang", "FTP"}, {"pezy", "CP5"}, {"wang", "CPP-Concurrency"}
    };
    // auto num = authors.erase(authors.find("wkm"));
    std::cout << "authors size: " << authors.size() << std::endl;
    for (const auto &item:authors)
        std::cout << item.first << " " << item.second << std::endl;
    /*
    authors size: 6: 
    alan DMA
    alan CLRS
    pezy LeetCode
    pezy CP5
    wang FTP
    wang CPP-Concurrency
    关键字有序，但是书籍不是有序
    网上的方法都是创建一个string-multiset<string>, 为什么？
    */
    std::map<std::string, std::multiset<std::string>> dest;
    for (const auto item : authors)
        dest[item.first].insert(item.second);
    
    std::cout << "排序后：" << std::endl;
    for (auto iter = dest.cbegin(); iter != dest.cend(); ++iter) {
        std::cout << (*iter).first << ": ";
        for (const auto &book_name:(*iter).second)
            std::cout << book_name << " ";    
        std::cout << std::endl;
    }
    
    return 0;
}
