#ifndef BLOB_H
#define BLOB_H
#include <stdexcept>
#include <initializer_list>
#include <string>
#include <vector>
#include <memory>
template <typename>
class BlobPtr;

template <typename>
class Blob;

template <typename T>
bool operator==(const Blob<T> &, const Blob<T> &);

template <typename T> class Blob {
    friend class BlobPtr<T>;
    friend bool operator==<T>(const Blob<T>&, const Blob<T>&);
public:
    typedef T value_type;
    typedef typename std::vector<T>::size_type size_type;
    Blob();
    template <typename It>
    // P596提到的“类模板的成员模板”
    Blob(It b, It e);
    Blob(T *, std::size_t);

    Blob(std::initializer_list<T> il);
    size_type size() const { return data->size(); }
    bool empty() const {return data->empty(); }
    void push_back(const T &input) {data->push_back(input); }
    
    BlobPtr<T> begin() { return BlobPtr<T>(*this);}
    BlobPtr<T> end() 
    {
        BlobPtr<T> ret = BlobPtr<T>(*this, data->size());
        return ret;
    }

    // 移动版本
    void push_back(T &&t) { data->push_back(std::move(t));}
    void pop_back();
    // 元素访问
    T& front();
    T& back();
    T& operator[](size_type);
    const T& operator[](size_type) const;
    T& back() const;
private:
    std::shared_ptr<std::vector<T>> data;
    void check(size_type i, const std::string &msg) const;
};

template <typename T>
bool operator==(const BlobPtr<T> &, const BlobPtr<T> &);

template <typename T> class BlobPtr {
    friend bool operator==<T>(const BlobPtr &lhs, const BlobPtr &rhs);
public:
    BlobPtr() : curr(0) { }
    BlobPtr(Blob<T> &info, size_t sz = 0) : 
        wptr(info.data), curr(sz) { }
    //std::string& deref() const;
    //BlobPtr& incr();
    T& operator[](std::size_t i) 
    {
        std::shared_ptr<std::vector<T>> p = 
            check(i, "subscript out of range");
        return (*p)[i];
    }
    const T& operator[](std::size_t i) const 
    {
        std::shared_ptr<std::vector<T>> p = 
            check(i, "subscript out of range");
        return (*p)[i];
    }

    T& operator*() const 
    {
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }
    T* operator->() const { return &this->operator*();  }
    BlobPtr& operator++();
    BlobPtr& operator--();
    BlobPtr operator++(int);
    BlobPtr operator--(int);

private:
    std::shared_ptr<std::vector<T>>
        check(std::size_t, const std::string&) const;
    std::weak_ptr<std::vector<T>> wptr;
    std::size_t curr;
};

template <typename T>
Blob<T>::Blob(): data(std::make_shared<std::vector<T>>()) { } 

template <typename T>
Blob<T>::Blob(std::initializer_list<T> il): 
                    data(std::make_shared<std::vector<T>>(il)) { }

template <typename T>
template <typename It>
Blob<T>::Blob(It b, It e) : 
    data(new std::vector<T>(b, e)) {}

template <typename T>
Blob<T>::Blob(T *p, std::size_t n):
    data(new std::vector<T>(p, p+n)) {}

template <typename T>
void Blob<T>::check(size_type i, const std::string &msg) const
{
    if (i >= msg.size())
        throw std::out_of_range(msg);
}
template <typename T>
T& Blob<T>::front()
{
    check(0, "front on Blob<T>");
    return data->front();
}

template <typename T>
T& Blob<T>::back()
{
    check(0, "back on Blob<T>");
    return data->back();
}

template <typename T>
T& Blob<T>::back() const 
{
    check(0, "back on Blob<T>");
    return data->back();
}

template <typename T>
void Blob<T>::pop_back() 
{
    check(0, "pop_back on empty Blob<T>");
    data->pop_back();
}

template <typename T>
T& Blob<T>::operator[](size_type i)
{
    check(i, "subscript out of range");
    return (*data)[i];
}

template <typename T>
const T& Blob<T>::operator[](size_type i) const 
{
    check(i, "subscript out of range");
    return (*data)[i];
}
template <typename T>
bool
operator==(const Blob<T> lhs, const Blob<T> rhs) {
    if (rhs.size() != lhs.size())
        return false;
    for (size_t i = 0; i < lhs.size(); ++i) {
        if (lhs[i] != rhs[i])
            return false;
    }
    return true;
}

//********************** BlobPtr *********************
template <typename T>
std::shared_ptr<std::vector<T>>
    BlobPtr<T>::check(std::size_t i, const std::string &msg) const
{
    std::shared_ptr<std::vector<T>> ret = wptr.lock();
    if (!ret)
        throw std::runtime_error("unbound BlobPtr<T>");
    if (i >= msg.size())
        throw std::out_of_range(msg);
    return ret;
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator++()
{
    check(curr, "increment past end of BlobPtr<T>");
    ++curr;
    return *this;
}
template <typename T>
BlobPtr<T>& BlobPtr<T>::operator--()
{
    --curr;
    check(curr, "decrement past begin of BlobPtr<T>");
    return *this;
}
template <typename T>
BlobPtr<T> BlobPtr<T>::operator--(int)
{
    BlobPtr ret = *this;
    --*this;
    return ret;
}
template <typename T>
BlobPtr<T> BlobPtr<T>::operator++(int)
{
    BlobPtr ret = *this;
    ++*this;
    return ret;
}

template <typename T>
bool operator==(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) 
{
    return lhs.wptr.lock().get() == rhs.wptr.lock().get() &&
            lhs.curr == rhs.curr;
}
template <typename T>
bool operator!=(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
    return !(lhs == rhs);
}
#endif