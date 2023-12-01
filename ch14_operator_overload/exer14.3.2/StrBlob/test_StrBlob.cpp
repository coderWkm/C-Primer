#include <iostream>
#include <initializer_list>
#include "StrBlobPtr.h"
using namespace std;
int main()
{
    StrBlob b1;
    {
        StrBlob b2 = {"a", "an", "the"};
        b1 = b2;
        b2.push_back("about");
        cout << b2.size() << endl;
    }
    // b2 在花括号外失效，作用域仅限于花括号内
    // cout << b2.size() << endl;
    cout << b1.size() << endl;
    cout << b1.front() << " " << b1.back() << endl;

    StrBlob b3 = b1;
    cout << b3.front() << " " << b3.back() << endl;

    // 针对练习 14.16 重载运算符 != 的调用
    for (auto iter = b1.begin(); iter != b1.end(); iter.incr())
        cout << iter.deref() << " ";
    cout << endl;
    return 0;
}