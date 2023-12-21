#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
//using std::placeholders::_1;
using namespace std::placeholders;

bool check_size(const std::string &word, std::string::size_type sz)
{
    return word.size() >= sz;
}

int main()
{
    std::vector<std::string> words{
        "aaa", "bbbb", "Cc", "waeoprkfjdslk",
        "z;slq[03-]", "his", "we"
    };    
    auto check6 = bind(check_size, _1, 6);
    std::string s("helloaaaaa");
    bool b1 = check6(s);
    std::cout << b1 << std::endl;
    std::cout << "***************************" << std::endl;
    auto iter = std::find_if(words.cbegin(), words.cend(), 
                                check6);
    for (; iter != words.cend(); ++iter)
        std::cout << *iter << " ";

    return 0;
}
