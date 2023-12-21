#include "HasPtr.h"

int main() {
    HasPtr h("hi mom!");
    HasPtr h2(h);
    HasPtr h3 = h;
    h2 = h3;
    h2 = std::move(h3);

    return 0;
}
/*
constructor -- hi mom!
copy constructor -- hi mom!
copy constructor -- hi mom!
copy constructor -- hi mom!
move constructor -- hi mom!

当注释掉赋值运算符的声明与实现，取消拷贝赋值运算符和移动赋值运算符的声明与实现的注释后，再次运行程序。
结果如下：
constructor -- hi mom!
copy constructor -- hi mom!
copy constructor -- hi mom!
copy-assignment operator -- hi mom!
move-assignment operator -- hi mom!
*/