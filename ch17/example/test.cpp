#include <iostream>
#include <string>
/**
 * 测试P393跳过前导空格的原因
*/
int main()
{
    std::string word1, word2;
    std::cin >> word1;
    getline(std::cin, word2);
    std::cout << word1 << ", " << word1.size() << std::endl;
    std::cout << word2 << ", " << word2.size() << std::endl;
    return 0;
}