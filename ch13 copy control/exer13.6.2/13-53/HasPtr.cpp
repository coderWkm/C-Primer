#include "HasPtr.h"
#include <iostream>

inline
void swap(HasPtr &lhs, HasPtr &rhs) {
    using std::swap;
    swap(lhs.ps, rhs.ps);                   // 交换指针，而不是 string 数据
    swap(lhs.i, rhs.i);                     // 交换 int 成员
}

HasPtr::HasPtr(const std::string &s)
    : ps(new std::string(s)), i(0) {
    std::cout << "constructor -- " << s << std::endl;
}

HasPtr::HasPtr(const HasPtr &orig) :
    ps(new std::string(*orig.ps)), i(orig.i) {
    std::cout << "copy constructor -- " << *orig.ps << std::endl;
}

// 注意 rhs 是按值传递的，意味着 HasPtr 的拷贝构造函数
// 将右侧运算对象中 string 拷贝到 rhs
HasPtr& HasPtr::operator=(HasPtr rhs) {
    // 交换左侧运算对象和局部变量 rhs 的内容
    swap(*this, rhs);                       // rhs 现在指向本对象曾经使用的内存
    return *this;                           // rhs 被销毁，从而 delete 了 rhs 中的指针
}

HasPtr::HasPtr(HasPtr &&p) noexcept         // 移动操作不应抛出任何异常
// 成员初始化器接管 p 中的资源
        : ps(p.ps), i(p.i) {
    std::cout << "move constructor -- " << *p.ps << std::endl;

    // 令 p 进入这样的状态 —— 对其运行析构函数是安全的
    p.ps = nullptr;
    p.i = 0;
}

HasPtr::~HasPtr() {
    delete ps;                              // 释放 string 内存
}

//HasPtr& HasPtr::operator=(const HasPtr &rhs) {
//    std::cout << "copy-assignment operator -- " << *rhs.ps << std::endl;
//
//    std::string *newps = new std::string(*rhs.ps);  // 拷贝指针指向的对象
//    delete ps;                                      // 销毁原 string
//    ps = newps;                                     // 指向新 string
//    i = rhs.i;                                      // 使用内置的 int 赋值
//    return *this;                                   // 返回一个此对象的引用
//}
//
//HasPtr& HasPtr::operator=(HasPtr &&rhs) noexcept {
//    std::cout << "move-assignment operator -- " << *rhs.ps << std::endl;
//
//    // 直接检测自赋值
//    if (this != &rhs) {
//        delete ps;                          // 释放旧 string
//        ps = rhs.ps;                        // 从 rhs 接管 string
//        rhs.ps = nullptr;                   // 将 rhs 置于可析构状态
//        rhs.i = 0;
//    }
//    return *this;
//}
