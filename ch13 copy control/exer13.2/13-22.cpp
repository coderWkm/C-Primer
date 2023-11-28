#include <iostream>
#include "13-22.h"

int main()
{
    HasPtr p1("aaaa");
    HasPtr p2(p1);
    std::cout << p1.get_strAddr() << ": " << *(p1.get_strAddr()) << std::endl;
    std::cout << p2.get_strAddr() << ": " << *(p2.get_strAddr()) << std::endl;
    /*
        0x1f1a90: aaaa
        0x1f1ae0: aaaa
    */ 
    HasPtr p3;
    p3 = p1;
    std::cout << p3.get_strAddr() << ": " << *(p3.get_strAddr()) << std::endl;
    // 0x1f1f10: aaaa
    return 0;
}
