#include <iostream>
#include <string>
#include <list>

int main()
{
    std::list<std::string> ilist{
        "the", "quick", "red", "fox", "jumps",
        "over", "the", "slow", "red", "turtle"
    };
    ilist.sort();
    ilist.unique();
    for (const auto &value:ilist)
        std::cout << value << " ";
    
    return 0;
}
