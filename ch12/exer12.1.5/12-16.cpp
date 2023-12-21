#include <iostream>
#include <memory>
#include <string>

int main()
{
    std::unique_ptr<std::string> p1(new std::string("aaaaa"));
    //std::unique_ptr<std::string> p2 = p1;
    /*
    function "std::unique_ptr<_Tp, _Dp>::unique_ptr(const std::unique_ptr<_Tp, _Dp> &) 
    [with _Tp=std::__cxx11::string, _Dp=std::default_delete<std::__cxx11::string>]" 
    (declared at line 394 of "D:\CodingTools\CandCpp\MinGW64\lib\gcc\x86_64-w64-mingw32\8.1.0\include\c++\bits\unique_ptr.h")
    cannot be referenced 
    -- it is a deleted functionC/C++(1776)
    */  
    // 这是一个被删除的函数：即unique_ptr中删除了复制或者拷贝构造函数!
    return 0;
}
