#ifndef HAS_PTR_H
#define HAS_PTR_H

#include <string>

class HasPtr{
public:
    HasPtr(const std::string &s = std::string()):
        ps(new std::string(s)), i(0) { }
    HasPtr(const HasPtr &);
private:
    std::string *ps;
    int i;
};

HasPtr::HasPtr(const HasPtr &value): 
    ps(new std::string(*(value.ps))), i(value.i) { }
/*
    ps和i成员都是private的，为什么还是可以通过成员运算符.访问？
*/
#endif