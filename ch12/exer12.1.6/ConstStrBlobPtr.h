#ifndef CONST_STRBLOBPTR_H
#define CONST_STRBLOBPTR_H
#include <memory>
#include <vector>
#include <string>
#include <stdexcept>
class StrBlobPtr;
class StrBlob {
public:
    friend class StrBlobPtr;
    typedef std::vector<std::string>::size_type size_type;
    StrBlob();
    StrBlob(std::initializer_list<std::string> il);
    size_type size() const { return data->size(); }
    bool empty() const {return data->empty(); }
    void push_back(const std::string &input) {data->push_back(input); }
    void pop_back();
    // 元素访问
    std::string& front();
    std::string& back();
    // StrBlobPtr
    StrBlobPtr begin();
    StrBlobPtr end();
    StrBlobPtr begin() const;
    StrBlobPtr end() const;
private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(size_type i, const std::string &msg) const;
};

//************************StrBlobPtr*********************
class StrBlobPtr {
    friend bool equal(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
public:
    StrBlobPtr() : curr(0) { }
    StrBlobPtr(const StrBlob &info, size_t sz = 0) : 
        wptr(info.data), curr(sz) { }
    std::string& deref() const;
    StrBlobPtr& incr();
private:
    std::shared_ptr<std::vector<std::string>>
        check(std::size_t, const std::string&) const;
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr;
};


// StrBlob成员函数
StrBlob::StrBlob(): data(std::make_shared<std::vector<std::string>>()) { } 
StrBlob::StrBlob(std::initializer_list<std::string> il): 
                    data(std::make_shared<std::vector<std::string>>(il)) { }
void StrBlob::check(StrBlob::size_type i, const std::string &msg) const
{
    if (i >= msg.size())
        throw std::out_of_range(msg);
}
std::string& StrBlob::front()
{
    check(-1, "front on StrBlob");
    return data->front();
}
std::string& StrBlob::back()
{
    check(-1, "back on StrBlob");
    return data->back();
}
void StrBlob::pop_back() 
{
    check(-1, "pop_back on empty StrBlob");
    data->pop_back();
}
StrBlobPtr StrBlob::begin() {
    return StrBlobPtr(*this);
}
StrBlobPtr StrBlob::end() {
    auto ret = StrBlobPtr(*this, data->size());
    return ret;
}
StrBlobPtr StrBlob::begin() const{
    return StrBlobPtr(*this);
}
StrBlobPtr StrBlob::end() const{
    auto ret = StrBlobPtr(*this, data->size());
    return ret;
}

// StrBlobPtr成员函数定义

std::shared_ptr<std::vector<std::string>>
    StrBlobPtr::check(std::size_t i, const std::string &msg) const
{
    std::shared_ptr<std::vector<std::string>> ret = wptr.lock();
    if (!ret)
        throw std::runtime_error("unbound StrBlobPtr");
    if (i >= msg.size())
        throw std::out_of_range(msg);
    return ret;
}

std::string& StrBlobPtr::deref() const

{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

StrBlobPtr& StrBlobPtr::incr()
{
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

// 比较StrBlobPtr相等
bool equal(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    auto l = lhs.wptr.lock(), r = rhs.wptr.lock();
    if (l == r) {
        return (!r || lhs.curr == rhs.curr);
    }
    else
        return false;
}
#endif