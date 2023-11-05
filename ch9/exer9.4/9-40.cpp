#include <iostream>
#include <vector>
#include <string>

// 重要的是，在输入1000个字符串，重新resize后：
// 原本1024大小的vector增长到2000，size:1500；
// 因此MinGW编译器的vector增长模式也不是完全的翻倍扩充capacity

int main()
{
    std::vector<std::string> svec;
    svec.reserve(1024);
    std::string word;
    int i = 0;
    while (i != 256) {
        svec.push_back("aaa");
        ++i;
    }
    svec.resize(svec.size() + svec.size()/2);
    std::cout << svec.size() << std::endl; // 384
    std::cout << svec.capacity() << std::endl;  // 1021

    svec.clear();
    i = 0;
    while (i != 512) {
        svec.push_back("aaa");
        ++i;
    }
    svec.resize(svec.size() + svec.size()/2);
    std::cout << svec.size() << std::endl;  // 768
    std::cout << svec.capacity() << std::endl; // 1024
    
    svec.clear();
    i = 0;
    while (i != 1000) {
        svec.push_back("aaa");
        ++i;
    }
    svec.resize(svec.size() + svec.size()/2); 
    std::cout << svec.size() << std::endl;  // 1500
    std::cout << svec.capacity() << std::endl;  // 2000
    
    svec.clear();
    i = 0;
    while (i != 1024) {
        svec.push_back("aaa");
        ++i;
    }
    svec.resize(svec.size() + svec.size()/2);
    std::cout << svec.size() << std::endl;   // 1536
    std::cout << svec.capacity() << std::endl;  // 2000
    return 0;
}
