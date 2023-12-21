#include <iostream>
#include <utility>
#include <string>
#include <vector>

int main()
{
    std::vector<std::pair<std::string, int>> pairs;
    std::string str;
    int num;
    while (std::cin>> str >> num) {
        //std::make_pair();
        // 1.
        //pairs.push_back(std::make_pair(str, num));
        // 2.
        // std::pair<std::string, int> input(str, num);
        // 3.
        std::pair<std::string, int> input = {str, num};
        pairs.push_back(input);
    }
    std::cout << "pair size:" << pairs.size() << std::endl;
    for (auto citer = pairs.cbegin(); citer != pairs.cend(); ++citer) {
        std::cout << (*citer).first << "--->" << (*citer).second <<std::endl;
    }
    
    return 0;
}
