#ifndef HAS_PTR
#define HAS_PTR

#include <string>
#include <iostream>

class HasPtr{
    friend void swap(HasPtr &, HasPtr &);
public:
    HasPtr(const std::string &s = std::string()):
        ps(new std::string(s)), i(0), use(new std::size_t(1)) { }
    HasPtr(const HasPtr &p):
        i(p.i), ps(p.ps), use(p.use) { ++*use; }
    HasPtr& operator=(const HasPtr&);
    ~HasPtr();
    // P460添加<运算符
    bool operator<(const HasPtr&) const;

    //用于测试cpp执行的公共函数
    std::string* get_ps() {return ps;}
    std::size_t* get_use() {return use;}
    int get_i() {return i;}
private:
    int i;
    std::string *ps;
    std::size_t *use;  // 共享*ps的个数
};

HasPtr&
HasPtr::operator=(const HasPtr& rhs)
{
    // 先++右侧运算对象
    ++*rhs.use; // 解引用*和前置++优先级相同，且均为右结合
    if (--*use == 0) {  // 再--左侧运算对象
        delete ps;
        delete use;
    } 
    ps = rhs.ps;
    i = rhs.i;
    use = rhs.use;
    return *this;
}

HasPtr::~HasPtr()
{
    if (--*use == 0) {
        delete ps;
        delete use;
    }
}
inline void swap(HasPtr &lhs, HasPtr &rhs)
{
    using std::swap;
    swap(lhs.i, rhs.i);
    swap(lhs.ps, rhs.ps);
    swap(lhs.use, rhs.use);
    std::cout << "交换结束！" << std::endl;
}

bool HasPtr::operator<(const HasPtr& rhs) const
{
    return *ps > *rhs.ps;
}
#endif