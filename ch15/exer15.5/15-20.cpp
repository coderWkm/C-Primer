#include <iostream>

class Base {
public:
    void pub_mem();
protected:
    int prot_mem;
private:
    char priv_mem;
};
//  第二条：继承Base的直接派生类D1、D2、D3
struct Pub_Derv: public Base {
    int f() {return prot_mem;}
    //char g() {return priv_mem;}
    void memfcn(Base &b) { b = *this; }
};
struct Pro_Derv : protected Base {
    void memfcn(Base &b) { b = *this; } 
};
struct Priv_Derv: private Base {
    int f1() const {return prot_mem;}
};

// 第三条：D1-D3的派生类
struct Derived_from_Public : public Pub_Derv {
    int use_base() { return prot_mem;} 
    void memfcn(Base &b) { b = *this; }
};
struct Derived_from_Private : public Priv_Derv {
    // int use_base() { return prot_mem;} 
    // void memfcn(Base &b) { b = *this; }
    // 不允许对不可访问的基类 "Base" 进行转换C/C++(269
};
struct Derived_from_Pro : public Pro_Derv
{
    void memfcn(Base &b) { b = *this; }
};

int main()
{
    Pub_Derv d1;
    Priv_Derv d2;
    Pro_Derv d3;
    Derived_from_Public dd1;
    Derived_from_Pro dd3;
    Derived_from_Private dd2;
    
    Base *p = &d1;
    //p = &d2;
    //p = &d3;
    p = &dd1;
    //p = &dd2;
    //p = &dd3;
    // 不允许对不可访问的基类 "Base" 进行转换C/C++(269
    return 0;
}
