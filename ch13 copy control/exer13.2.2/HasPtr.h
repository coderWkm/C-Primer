#ifndef HAS_PTR
#define HAS_PTR

#include <string>

class HasPtr{
public:
    HasPtr(const std::string &s = std::string()):
        ps(new std::string(s)), i(0), use(new std::size_t(1)) { }
    HasPtr(const HasPtr &p):
        i(p.i), ps(p.ps), use(p.use) { ++*use; }
    HasPtr& operator=(const HasPtr&);
    ~HasPtr();

    //用于测试cpp执行的公共函数
    std::string* get_ps() {return ps;}
    std::size_t* get_use() {return use;}
    int get_i() {return i;}
private:
    int i;
    std::string *ps;
    std::size_t *use;
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
#endif