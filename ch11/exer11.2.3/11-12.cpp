#include <iostream>
#include <utility>
#include <string>
#include <vector>

int main()
{
    std::vector<std::pair<std::string, int>> pairs;
    std::pair<std::string, int> input;
    std::string str;
    int num;
    while (std::cin>> str >> num) {
        //std::make_pair();
        pairs.push_back(std::make_pair(str, num));
    }
    std::cout << "pair size:" << pairs.size() << std::endl;
    for (auto citer = pairs.cbegin(); citer != pairs.cend(); ++citer) {
        std::cout << (*citer).first << "--->" << (*citer).second <<std::endl;
        // 解引用的优先级小于成员选择运算符
    }
    
    return 0;
}
