#ifndef TEST_STRBLOB_H
#define TEST_STRBLOB_H

#include <vector>
#include <string>
#include <initializer_list>
#include <memory>
#include <stdexcept>

using std::string;
using std::vector;
using std::initializer_list;
using std::shared_ptr;
using std::weak_ptr;
using std::make_shared;
using std::out_of_range;
using std::runtime_error;

// 对于 StrBlob 中的友元声明来说，此前置声明是必要的
class StrBlobPtr;
class StrBlob {
    friend class StrBlobPtr;
    // 练习 14.16
    friend bool operator==(const StrBlob &lhs, const StrBlob &rhs);
    friend bool operator!=(const StrBlob &lhs, const StrBlob &rhs);
    friend bool operator<(const StrBlob &lhs, const StrBlob &rhs);

public:
    typedef vector<string>::size_type size_type;
    StrBlob();
    StrBlob(initializer_list<string> il);
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    // 添加和删除元素
    void push_back(const string &t) { data->push_back(t); }
    void pop_back();
    // 元素访问
    string& front();
    const string& front() const;
    string& back();
    const string& back() const;

    // 提供给 StrBlobPtr 的接口
    // 返回指向首元素和尾后元素的 StrBlobPtr
    StrBlobPtr begin();     // 定义 StrBlobPtr 后才能定义这两个函数
    StrBlobPtr end();

private:
    shared_ptr<vector<string>> data;
    // 如果 data[i] 不合法，抛出一个异常
    void check(size_type i, const string &msg) const;
};

class StrBlobPtr {
    // 练习 14.16
    friend bool equal(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
    friend bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
    friend bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
    friend bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
public:
    StrBlobPtr() : curr(0) {}
    StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}

    string& deref() const;
    StrBlobPtr& incr();     // 前缀递增
    StrBlobPtr& decr();     // 后缀递减
private:
    // 若检查成功，check 返回一个指向 vector 的 shared_ptr
    shared_ptr<vector<string>> check(size_t, const string&) const;
    // 保存一个 weak_ptr，意味着底层 vector 可能会被销毁
    weak_ptr<vector<string>> wptr;
    size_t curr;            // 在数组中的当前位置
};

#endif //TEST_STRBLOB_H