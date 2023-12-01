#include "String.h"

#include <algorithm>
using std::for_each;

allocator<char> String::a;

void String::free() {
    if (p) {
        for_each(p, p + sz, [this] (char &c) { a.destroy(&c); });
        a.deallocate(p, sz);
    }
}

void String::swap(String &s) {
    char *tmp = p;
    p = s.p;
    s.p = tmp;

    size_t cnt = sz;
    sz = s.sz;
    s.sz = cnt;
}

String& String::operator=(const String &rhs) {
    std::cout << "拷贝赋值运算符1: String" << std::endl;
    char *newp = a.allocate(rhs.sz);    
    uninitialized_copy(rhs.p, rhs.p + rhs.sz, newp);
    free();         
    p = newp;       
    sz = rhs.sz;    
    return *this;
}

String& String::operator=(const char *cp) {
    std::cout << "拷贝赋值运算符2: char*" << std::endl;
    free();         
    p = a.allocate(sz = strlen(cp));
    uninitialized_copy(cp, cp + sz, p);
    return *this;
}

String& String::operator=(char c) {
    std::cout << "拷贝赋值运算符3: char" << std::endl;
    free();         
    p = a.allocate(sz = 1);
    *p = c;
    return *this;
}

ostream &print(ostream &os, const String &s) {
    const char *p = s.begin();
    while (p != s.end())
        os << *p++;
    return os;
}

String add(const String &lhs, const String &rhs) {
    String ret;
    ret.sz = rhs.size() + lhs.size();       
    ret.p = String::a.allocate(ret.sz);     
    uninitialized_copy(lhs.begin(), lhs.end(), ret.p);  
    uninitialized_copy(rhs.begin(), rhs.end(), ret.p + lhs.sz);
    return ret;
}

String make_plural(size_t ctr, const String &word, const String &ending) {
    return (ctr != 1) ? add(word, ending) : word;
}

ostream &operator<<(ostream &os, const String &s) {
    return print(os, s);
}

String operator+(const String &lhs, const String &rhs) {
    return add(lhs, rhs);
}
