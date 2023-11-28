#include "StrVec.h"
/*
    书中隐含的类实现的思想：
        1. 先实现类的构造函数；
            1.1 对于拷贝构造函数和拷贝赋值运算符，需要先实现——————>alloc_n_copy、free
                1.1.1 alloc_n_copy
                1.1.2 free： 拷贝赋值要用
*/
std::allocator<std::string> StrVec::alloc;   // static成员需要在类外定义

void StrVec::push_back(const std::string &str)
{
    chk_n_alloc();
    alloc.construct(first_free++, str);
}
std::pair<std::string*, std::string*>
    StrVec::alloc_n_copy(const std::string *beg, const std::string *end)
{
    auto data = alloc.allocate(end - beg);
    return {data, uninitialized_copy(beg, end, data)};
}
void StrVec::free()
{
    if (elements) { // 必须先判断elements是否为空
        for (auto p = first_free; p != elements; )
            alloc.destroy(--p);
        alloc.deallocate(elements, cap - elements);
    }
}
StrVec::StrVec(const StrVec &copy)
{
    auto data = alloc_n_copy(copy.begin(), copy.end());
    elements = data.first;
    first_free = cap = data.second;  // cap也在这赋值，是因为alloc_n_copy分配的内存大小，就是传入的字符串的大小
}
StrVec::StrVec(const std::initializer_list<std::string> &args)
{
    auto data = alloc_n_copy(args.begin(), args.end());
    elements = data.first;
    first_free = cap = data.second;
}
StrVec&
    StrVec::operator=(const StrVec& rhs)
{
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}
StrVec::~StrVec()
{
    free();
}
void StrVec::reallocate()
{
    auto newcapacity = size() ? 2*size() : 1;
    auto newdata = alloc.allocate(newcapacity);
    auto dest = newdata;
    auto elem = elements; 
    for (size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, std::move(*elem++));
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}