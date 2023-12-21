#include <iostream>
#include <iterator>
#include <string>
#include <fstream>
#include <vector>

int main()
{
    std::ifstream is("10-29.txt");
    std::istream_iterator<std::string> input(is), eof;
    std::ostream_iterator<std::string> output(std::cout, " ");
    std::vector<std::string> res;
    while (input != eof) {
        res.push_back(*input++);
    }
    std::cout << "结果大小：" << res.size() << "，成员情况：" << std::endl;
    for (const std::string &str : res)
        *output++ = str;
    
    return 0;
}
