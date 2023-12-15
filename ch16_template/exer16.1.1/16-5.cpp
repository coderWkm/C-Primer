#include <iostream>
#include <vector>
#include <string>

template <typename T, unsigned N>
void print(const T (&arr)[N])
{
    for (auto elem : arr)
        std::cout << elem << " ";   
}
int main()
{
    int a[] = {1, 2, 3, 4, 5, 1, 1, 1};
    print(a);
    /*
    std::vector<std::string> strs{"aaa", "bbb", "Ccc"};
    print(strs);
    提示不匹配函数
    */
    std::string strs[] = {"aaa", "bbb", "ccc"};
    print(strs);
    return 0;
}
