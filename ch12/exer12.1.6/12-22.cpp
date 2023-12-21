#include <iostream>
#include "ConstStrBlobPtr.h"

/*
    1. StrBlob构造函数添加const
    2. begin、end提供const的版本，因为b对象是const
*/

int main()
{
    const StrBlob b{"Hello", "World", "!!!"};
    for (auto iter = b.begin(); !equal(iter, b.end()); iter.incr())
        std::cout << iter.deref() << " ";
    
    return 0;
}
