#include <iostream>

int main()
{
    // 没有与参数列表匹配的 重载函数 "std::max" 实例C/C++(304)
    // std::max(1, 2.65);    

    // 需要显示指定模板实参，用于正常的类型转换；否则的话只能输入类型相同的参数
    std::cout << std::max<int>(1, 2.65) << std::endl;
    // 2
    return 0;
}
