#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

void print_longer_words(std::vector<std::string> &words);
inline bool longer_than_5(const std::string &word)
{
    return (word.size() >= 5 ? true : false);
}

int main()
{
    std::vector<std::string> words{
        "aaa", "aaaaaa", "bbbbb", "ccccccccccccccccc"
        "dd", "e",
    };
    std::cout << "原vector：" << std::endl;
    for (auto iter = words.cbegin(); iter != words.cend(); ++iter)
        std::cout << *iter << " ";
    std::cout << std::endl;
    std::cout << "vector中长度>=5的：" << std::endl;
    print_longer_words(words); 
    std::cout << std::endl;
    std::cout << "partition后vector：" << std::endl;
    for (auto iter = words.cbegin(); iter != words.cend(); ++iter)
        std::cout << *iter << " ";

    
    return 0;
}

void print_longer_words(std::vector<std::string> &words)
{
    std::vector<std::string>::iterator longer_next = 
        partition(words.begin(), words.end(), longer_than_5);
    for (auto iter = words.begin(); iter != longer_next; ++iter)
        std::cout << *iter << " ";
}
