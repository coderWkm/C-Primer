#ifndef STRVEC_H
#define STRVEC_H

#include <string>
#include <memory>
#include <utility>
#include <initializer_list>
class StrVec {
    friend bool operator==(const StrVec&, const StrVec&);
    friend bool operator!=(const StrVec&, const StrVec&);
public:
    StrVec(): 
        elements(nullptr), first_free(nullptr), cap(nullptr) { }
    StrVec(const StrVec &);
    StrVec(const std::initializer_list<std::string>&);
    StrVec& operator=(const StrVec &);
    ~StrVec();
    void push_back(const std::string&);
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - first_free; }
    std::string *begin() const { return elements; }
    std::string *end() const { return first_free; }
private:
    static std::allocator<std::string> alloc;
    std::pair<std::string*, std::string*> alloc_n_copy(
        const std::string*, const std::string*
    );
    void free();
    void chk_n_alloc()  {   if (first_free == cap) reallocate();}
    void reallocate();
    std::string *elements;
    std::string *first_free;
    std::string *cap;
};
bool operator==(const StrVec&, const StrVec&);
bool operator!=(const StrVec&, const StrVec&);
#endif