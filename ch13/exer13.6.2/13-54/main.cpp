#include "HasPtr.h"

int main() {
    HasPtr h("hi mom!");
    HasPtr h2(h);
    HasPtr h3 = h;
    h2 = h3;
    h2 = std::move(h3);
    /*
    有多个运算符 "=" 与这些操作数匹配:C/C++(350)
    main.cpp(8, 8): 函数 "HasPtr::operator=(HasPtr)" (已声明 所在行数:12，所属文件:"xxx\HasPtr.h")
    main.cpp(8, 8): 函数 "HasPtr::operator=(HasPtr &&)" (已声明 所在行数:17，所属文件:"xxx\HasPtr.h")
    main.cpp(8, 8): 操作数类型为: HasPtr = HasPtr
    */

    return 0;
}
