#include <iostream>
using std::cout; using std::endl;

#include <typeinfo>

template<typename T>
void f(T) {
    cout << typeid(T).name() << "\ttemplate 1\n";
}

template<typename T>
void f(const T *) {
    cout << typeid(T).name() << "\ttemplate 2\n";
}

template<typename T>
void g(T) {
    cout << typeid(T).name() << "\ttemplate 3\n";
}

template<typename T>
void g(T *) {
    cout << typeid(T).name() << "\ttemplate 4\n";
}
template <typename T> void f(T);                   
template <typename T> void f(const T*);            
template <typename T> void g(T);                   
template <typename T> void g(T*);                  
int i = 42, *p = &i;
const int ci = 0, *p2 = &ci;
int main()
{
    int i = 42, *p = &i;
    const int ci = 0, *p2 = &ci;
    g(42);
    g(p);
    g(ci);
    g(p2);
    f(42);
    f(p);
    f(ci);
    f(p2);
    return 0;
}
