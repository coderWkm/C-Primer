#ifndef STRING_H
#define STRING_H
#include <iostream>
using std::ostream;

#include <cstring>

#include <memory>
using std::allocator;
using std::uninitialized_copy;
using std::uninitialized_fill_n;

class String {
    friend String operator+(const String&, const String&);
    friend String add(const String&, const String&);
    friend ostream &operator<<(ostream&, const String&);
    friend ostream &print(ostream&, const String&);
    friend bool operator==(const String&, const String&);
    friend bool operator!=(const String&, const String&);

public:
    String() : sz(0), p(0) { }
    String(const char *cp) : sz(strlen(cp)), p(a.allocate(sz)) {
        uninitialized_copy(cp, cp + sz, p);
    }
    String(size_t n, char c) : sz(n), p(a.allocate(n)) {
        uninitialized_fill_n(p, sz, c);
    }

    String(const String &s) : sz(s.sz), p(a.allocate(s.sz)) {
        std::cout << "拷贝构造函数 -- ";
        print(std::cout, s) << std::endl;
        uninitialized_copy(s.p, s.p + sz, p);
    }

    String &operator=(const String&);

    ~String() { free(); }

public:
    String &operator=(const char*);         
    String &operator=(char);                

    const char *begin() { return p; }
    const char *begin() const { return p; }
    const char *end() { return p + sz; }
    const char *end() const { return p + sz; }

    size_t size() const { return sz; }
    void swap(String&);

private:
    size_t sz;
    char *p;
    static allocator<char> a;

    void free();
};

String make_plural(size_t ctr, const String&, const String&);

inline
void swap(String &s1, String &s2) {
    s1.swap(s2);
}
bool operator==(const String&, const String&);
bool operator!=(const String&, const String&);
#endif 