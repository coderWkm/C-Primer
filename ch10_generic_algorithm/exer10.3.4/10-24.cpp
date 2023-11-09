#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std::placeholders;
bool check_size(const std::string &word, std::string::size_type sz)
{
    return word.size() <= sz;
}

int main()
{
    std::string str{"aaabbbccc"};
    std::vector<int> lens{5, 6, 7, 8, 9, 10, 11};
    auto iter = std::find_if(lens.cbegin(), lens.cend(), 
                std::bind(check_size, str, _1)); 
                // 一定要理解_1与bind绑定的函数参数的对应关系
                // 占位符_x出现在第几个位置，就是被绑定函数的第几个参数
                // 而_1、_2的先后关系，则是在调用bind返回的只执行对象时，传入该对象的第1、2参数
                // 结合P356的解释再理解
    std::cout << "第一个长度等于" << str << "的是：" << *iter << std::endl;
    return 0;
}
