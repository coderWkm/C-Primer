#include <iostream>
//#include "StrBlob.h"
#include "StrBlobPtr.h"
#include <fstream>

/*
    关于以下问题；
            错误: "error: return type 'class StrBlobPtr' is incomplete"
            错误: "error: invalid use of incomplete type 'class StrBlobPtr'"     
    https://blog.csdn.net/caroline_wendy/article/details/14222295
*/

int main()
{
    std::ifstream in("str_vec.txt");
    if (!in) {
        std::cerr << "打开文件失败！" << std::endl;
        return -1;
    }
    StrBlob info;
    //StrBlobPtr info_ptr(info);
    std::string word;
    while (in >> word) {
        info.push_back(word);
    }
    std::cout << "StrBlob保存完成！成员大小："
              << info.size() << "。成员有："
              << std::endl;
    for (auto iter = info.begin(); !equal(iter, info.end()); iter.incr()) {
        std::cout << iter.deref() << " ";
    }
    
    return 0;
}
