#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
/*
    重点比较erase后和stable_partition:
        erase后，大小是：8
        fox jumps over quick red slow the turtle
        stable_partition后：
        jumps over quick slow turtle fox red the
    前五个和后三个的相对顺序不变
*/

void elimDups(std::vector<std::string> &words);
std::string make_plural(size_t ctr, const std::string &word, 
                                    const std::string &ending)
{
    return (ctr > 1) ? word + ending : word;
}
void biggies(std::vector<std::string> words, 
                std::vector<std::string>::size_type sz);

int main()
{
    std::vector<std::string> strs{
        "the", "quick", "red", "fox", "jumps",
        "over", "the", "slow", "red", "turtle"
    };
    std::cout << "初始状态：" << std::endl;
    for(auto iter = strs.cbegin(); iter != strs.cend(); ++iter)
        std::cout << *iter << " ";
    std::cout << std::endl;
    biggies(strs, 4);
    
    return 0;
}

void biggies(std::vector<std::string> words, 
                std::vector<std::string>::size_type sz)
{
    elimDups(words);     
    /*
    std::sort(words.begin(), words.end(),
                    [](const std::string &a, const std::string &b) -> bool
                    { return a.size() < b.size(); });
    */
    auto wc = std::stable_partition(words.begin(), words.end(), 
                            [sz](const std::string word)
                            {return word.size() >= sz;} );
    std::cout << "stable_partition后：" << std::endl;
    std::for_each(words.begin(), words.end(), [](const std::string &s)
                                    {std::cout << s << " ";});
    std::cout << std::endl;
    // jumps over quick slow turtle fox red the

    auto count = wc - words.begin();
    std::cout << count << " " << make_plural(count, "word", "s")
              << " of length " << sz << " or longer" << std::endl;
    std::for_each(words.begin(), wc, [](const std::string &s)
                                    {std::cout << s << " ";});
    std::cout << std::endl;        
    // jumps over quick slow turtle
}

void elimDups(std::vector<std::string> &words)
{
    sort(words.begin(), words.end());
    std::cout << "经过排序后，大小是:" << words.size() << std::endl;
    for (auto iter = words.cbegin(); iter != words.cend(); ++iter)
        std::cout << *iter << " ";
    std::cout << std::endl;
    // fox jumps over quick red red slow the the turtle

    std::vector<std::string>::iterator last = unique(words.begin(), words.end());
    std::cout << "unique后，大小是：" << words.size() << std::endl;  
    for (auto iter = words.cbegin(); iter != words.cend(); ++iter)
        std::cout << *iter << " ";
    std::cout << std::endl;
    // fox jumps over quick red slow the turtle the

    words.erase(last, words.end());
    std::cout << "erase后，大小是：" << words.size() << std::endl;  
    for (auto iter = words.cbegin(); iter != words.cend(); ++iter)
        std::cout << *iter << " ";
    std::cout << std::endl;
    // fox jumps over quick red slow the turtle
}