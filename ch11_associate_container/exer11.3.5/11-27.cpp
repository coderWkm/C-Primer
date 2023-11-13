#include <iostream>
#include <map>
#include <string>
#include <vector>

int main()
{
    std::map<std::string, std::vector<int>> str2ivec{
        {"wkm", {10, 20, 30}},
        {"yyy", {66, 99, 999}}
    };
    auto iter = str2ivec.find("yyy");
    std::cout << (*iter).first << ":";
    for (auto vec_iter = (*iter).second.cbegin(); 
        vec_iter != (*iter).second.cend();
        ++vec_iter)
        std::cout << *vec_iter << " ";
    
    return 0;
}
