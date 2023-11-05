#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v{0, 1, 2, 3, 4};
    auto begin = v.begin();
    while (begin != v.end()) {
        ++begin;
        v.insert(begin, 42); // 下面是使用的原来的begin已经失效，导致段错误
        ++begin;
    }

    for (auto value:v) 
        std::cout << value << " ";
    
    return 0;
}
