#include "StrVec.h"
#include <algorithm>

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
        /*
        for (auto p = first_free; p != elements; )
            alloc.destroy(--p);
        */

        // for_each + lambda
        std::for_each(elements, first_free, [this](std::string& s){
           this->alloc.destroy(&s); 
        });        
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
/*
    移动构造函数、移动赋值运算符
*/
StrVec::StrVec(StrVec &&s) noexcept :
    elements(s.elements), first_free(s.first_free), cap(s.cap)
{
    s.elements = s.first_free = s.cap = nullptr;
}
StrVec& StrVec::operator=(StrVec &&rhs) noexcept
{
    if (this != &rhs) {
        free();
        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.cap;
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }
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