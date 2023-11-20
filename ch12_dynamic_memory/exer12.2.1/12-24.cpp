#include <iostream>

int main()
{
    std::cout << "输入字符串长度：";
    size_t len = 0;
    std::cin >> len;
    char *str = new char[len + 1]();
    std::cout << "输入字符串：";
    size_t i = 0;
    while (i != len) 
        std::cin >> str[i++];
    std::cout << "你输入的字符串：";
    i = 0;
    while (i != len)
        std::cout << str[i++];
    std::cout << std::endl;

    delete [] str;
    return 0;
}
