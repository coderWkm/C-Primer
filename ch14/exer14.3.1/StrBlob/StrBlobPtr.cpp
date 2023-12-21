#include "StrBlobPtr.h"

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
    check(-2, "front on StrBlob");
    return data->front();
}
std::string& StrBlob::back()
{
    check(-2, "back on StrBlob");
    return data->back();
}
void StrBlob::pop_back() 
{
    check(-2, "pop_back on empty StrBlob");
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
bool operator==(const StrBlob &lhs, const StrBlob &rhs)
{
    return *lhs.data == *rhs.data;
}
bool operator!=(const StrBlob &lhs, const StrBlob &rhs)
{
    return !(lhs == rhs);
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
bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    return equal(lhs, rhs);
}
bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    return !(lhs == rhs);
}