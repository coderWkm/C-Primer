#include <iostream>
#include <vector>
#include <string>

int main()
{
    // vecotr::data，返回内存空间首地址
    std::vector<char> chars{'a', 'e', 'i', 'o', 'u'};

    //传入chars.begin()和end()也是可以的，因为调用string的构造函数：
    //string(char* str, size_t count);
    //第二个长度参数可以通过begin-end传入，这是C++标准库的设计（答案来源于GPT）
    std::string c2str(chars.data(), chars.size());
    std::cout << c2str;

    return 0;
}
