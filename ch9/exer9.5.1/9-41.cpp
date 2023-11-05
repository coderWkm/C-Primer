#include <iostream>
#include <vector>
#include <string>

int main()
{
    // vecotr::data，返回内存空间首地址
    std::vector<char> chars{'a', 'e', 'i', 'o', 'u'};
    std::string c2str(chars.data(), chars.size());
    std::cout << c2str;

    return 0;
}
