#ifndef TEST_HASPTR_H
#define TEST_HASPTR_H

#include <string>

class HasPtr {
    friend void swap(HasPtr &, HasPtr &);

public:
    HasPtr(const std::string &s = std::string());
    HasPtr(const HasPtr &);                 // 拷贝构造函数
    HasPtr &operator=(HasPtr);              // 赋值运算符（拷贝并交换版本）
    HasPtr(HasPtr&&) noexcept;              // 移动构造函数
    ~HasPtr();                              // 析构函数

//    HasPtr &operator=(const HasPtr &);      // 拷贝赋值运算符
//    HasPtr &operator=(HasPtr&&) noexcept;   // 移动赋值运算符

private:
    std::string *ps;
    int i;
};

#endif //TEST_HASPTR_H
