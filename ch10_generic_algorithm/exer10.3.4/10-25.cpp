#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std::placeholders;
//erase: fox jumps over quick red slow the turtle 
//partition: turtle quick jumps over slow the red fox
// 相对顺序都变了

bool check_size(const std::string &word, std::string::size_type sz)
{
    return word.size() >= sz;
}
void elimDups(std::vector<std::string> &words);
void print(std::vector<std::string> &words);
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
    std::cout << "初始，大小为" << strs.size() << std::endl;
    print(strs);
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
    auto wc = std::partition(words.begin(), words.end(), 
                            //[sz](const std::string word)
                            //{return word.size() >= sz;}
                             bind(check_size, _1, sz));
    std::cout << "partition后：" << std::endl;
    std::for_each(words.begin(), words.end(), [](const std::string &s)
                                    {std::cout << s << " ";});
    std::cout << std::endl;
    std::cout << "************************" << std::endl;
    
    auto count = wc - words.begin();
    std::cout << count << " " << make_plural(count, "word", "s")
              << " of length " << sz << " or longer" << std::endl;
    std::for_each(words.begin(), wc, [](const std::string &s)
                                    {std::cout << s << " ";});
    std::cout << std::endl;        
    //turtle quick jumps over slow
}

void elimDups(std::vector<std::string> &words)
{
    sort(words.begin(), words.end());
    std::cout << "经过排序后，大小是:" << words.size() << std::endl;
    print(words);
    // fox jumps over quick red red slow the the turtle 

    std::vector<std::string>::iterator last = unique(words.begin(), words.end());
    std::cout << "unique后，大小是：" << words.size() << std::endl;  
    print(words);
    // fox jumps over quick red slow the turtle the  

    words.erase(last, words.end());
    std::cout << "erase后，大小是：" << words.size() << std::endl;  
    print(words);
}

void print(std::vector<std::string> &words)
{
    for (auto iter = words.cbegin(); iter != words.cend(); ++iter)
        std::cout << *iter << " ";
    std::cout << std::endl;
}