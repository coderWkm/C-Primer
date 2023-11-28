#ifndef HAS_PTR_H
#define HAS_PTR_H

#include <string>

class HasPtr{
public:
    HasPtr(const std::string &s = std::string()):
        ps(new std::string(s)), i(0) { }
    HasPtr(const HasPtr &);
    HasPtr& operator=(const HasPtr&);
    std::string* get_strAddr() { return ps; }
    ~HasPtr();
private:
    std::string *ps;
    int i;
};

/*
    ps和i成员都是private的，为什么还是可以通过成员运算符.访问？
*/
HasPtr::HasPtr(const HasPtr &value): 
    ps(new std::string(*(value.ps))), i(value.i) { }

HasPtr& HasPtr::operator=(const HasPtr &ptr_value)
{
    // ps = ptr_value.ps;  不能只赋值指针的值，应该是重新开辟一块区域存储相同的string内容

    /*
        !!!!!
        正好是P454强调的错误写法
    */
    ps = new std::string(*ptr_value.ps);  // .的优先级大于*
    i = ptr_value.i;
    return *this;
}

HasPtr::~HasPtr() 
{
    /*
        根据P453例子
        析构函数应该对成员ps先销毁：
        delete ps;
    */
}
#endif