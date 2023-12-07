#include <iostream>
class Base {
public:
    virtual int fcn() 
    { 
        std::cout << "Base fcn" << std::endl;
        return 0;
    }
};
class D1 : public Base {
public:
    // 继承Base中的fcn
    int fcn() 
    {
        std::cout << "D1 fcn() —————— Base fcn()" << std::endl;
        return 0;
    }
    virtual void f2() {std::cout << "D1 f2 " << std::endl;}
};
class D2 : public D1 {
public:
    int fcn(int) 
    { 
        std::cout << "D2 fcn(int)" << std::endl;
        return 0;
    }
    int fcn() override 
    { 
        std::cout << "D2 fcn()" << std::endl;
        return 0;
    }
    void f2() {std::cout << "D2 f2()" << std::endl;}
};
int main()
{
    // P550例子：
    Base bobj;
    D1 d1obj;
    D2 d2obj;

    Base *bp1 = &bobj, *bp2 = &d1obj, *bp3 = &d2obj;
    bp1->fcn();
    bp2->fcn();
    bp3->fcn();
    std::cout << std::endl;

    D1 *d1p = &d1obj;
    D2 *d2p = &d2obj;
    // bp2->f2();  //类 "Base" 没有成员 "f2"C/C++(135)
    d1p->f2();
    d2p->f2();
    std::cout << std::endl;

    Base *p1 = &d2obj;
    D1 *p2 = &d2obj;
    D2 *p3 = &d2obj;
    // p1->fcn(42);  // 函数调用中的参数太多C/C++(140) no matching function for call to 'Base::fcn(int)'gcc
    p2->fcn();
    p3->fcn(42);
    return 0;
}
