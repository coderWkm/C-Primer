#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
class longerSize {
public:
    longerSize(size_t n): sz(n) { }
    bool operator()(const std::string &str) 
    {
        return str.size() > sz;
    }
private:
    size_t sz;
};
class printStr {
    //printStr(const std::string &value) {}
    void operator()(const std::string& str) 
    {
        std::cout << str << " ";
    }
};

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
        "aa", "e", "zgqw,r", "fsk", "mvkzlsjfiq", "bkospa",
        "xkfop",
    };
    biggies(strs, 3);
    
    return 0;
}

void biggies(std::vector<std::string> words, 
                std::vector<std::string>::size_type sz)
{
    elimDups(words);     
    std::stable_sort(words.begin(), words.end(),
                    [](const std::string &a, const std::string &b) -> bool
                    { return a.size() < b.size(); });
    // 第一处lambda：找到第一个大于sz的
    /*
    auto wc = std::find_if(words.begin(), words.end(), 
                            [sz](const std::string word)
                            {return word.size() > sz;} );
    */
    auto wc = std::find_if(words.begin(), words.end(), longerSize(sz));
    
    auto count = words.end() - wc;
    std::cout << count << " " << make_plural(count, "word", "s")
              << " of length " << sz << " or longer" << std::endl;
    // 第二处：打印
    std::for_each(wc, words.end(), [](const std::string &s)
                                    {std::cout << s << " ";});
    std::cout << std::endl;        
}

void elimDups(std::vector<std::string> &words)
{
    sort(words.begin(), words.end());
    std::cout << "经过排序后，大小是:" << words.size() << std::endl;
    for (auto iter = words.cbegin(); iter != words.cend(); ++iter)
        std::cout << *iter << " ";
    std::cout << std::endl;
    std::vector<std::string>::iterator last = unique(words.begin(), words.end());
    std::cout << "unique后，大小是：" << words.size() << std::endl;  
    for (auto iter = words.cbegin(); iter != words.cend(); ++iter)
        std::cout << *iter << " ";
    std::cout << std::endl;
    words.erase(last, words.end());
}