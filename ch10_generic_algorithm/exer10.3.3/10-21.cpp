#include <iostream>

int main()
{
    int input;
    std::cin >> input;
    auto f = [input] () mutable -> bool
            {
                if (input > 0) {
                    --input;
                    return false;
                }
                else
                    return true;
            };
    bool tmp = false;
    while (tmp == false) {
        tmp = f();
        std::cout << "input: " << input 
                  << ", 是否为0：" << tmp << std::endl;
    }
    std::cout << "退出循环，input=" << input << std::endl;
    /*
        input: 3, 是否为0：0
        input: 3, 是否为0：0
        input: 3, 是否为0：0
        input: 3, 是否为0：1
        退出循环，input=3
        为什么input一直是3？
        因为lambda是创建时拷贝捕获值！！！！
        一开始while循环一直设置成input != 0, 所以跳不出循环，除非捕获引用。
    */
    return 0;
}
