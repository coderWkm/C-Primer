#include "Vec.h"

#include <string>
using std::string;

#include <iostream>
using std::cin; using std::cout; using std::endl;
using std::istream;

void print(const Vec<string> &svec) {
    for (string *it = svec.begin(); it != svec.end(); ++it)
        cout << *it << " ";
    cout << endl;
}

Vec<string> getVec(istream &is) {
    Vec<string> svec;
    string s;
    while (is >> s)
        svec.push_back(s);
    return svec;
}

int main() {
    Vec<string> svec = getVec(cin);
    print(svec);

    cout << "copy " << svec.size() << endl;
    Vec<string> svec2 = svec;
    print(svec2);

    cout << "assign" << endl;
    Vec<string> svec3;
    svec3 = svec2;
    print(svec3);

    Vec<string> v1, v2;
    Vec<string> getVec(istream &);
    v1 = v2;            // copy assignment
    v2 = getVec(cin);   // move assignment
    print(v1);
    print(v2);
    cout << "----- end -----";

    /*
        暂留一个问题：为什么将函数成员实现放在单独的cpp文件会出现以下问题：找不到这些被调用的函数的定义（push_back等）
        Vec<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >::push_back(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&)'
    */
    return 0;
}
