#include <iostream>
#include <string>
#include <forward_list>

typedef std::forward_list<std::string> flist;
void insert_after(flist &fl, std::string prev, std::string after);

int main()
{
    flist orig{"aaa", "bbb", "ccc", "dddd"};
    insert_after(orig, "bbbb", "wkm");
    for (auto citer = orig.cbegin(); citer != orig.cend(); ++citer)
        std::cout << *citer << " ";
    
    return 0;
}

void insert_after(flist &fl, std::string prev, std::string after)
{
    // bool is_exist = false;
    auto iter = fl.begin(), before_iter = fl.before_begin();
    for(; iter != fl.end(); ++iter) {
        if (*iter == prev) {
            std::cout << prev << "存在！" << std::endl;
            break;
        }
        before_iter = iter;
    }
    if (iter == fl.end()) {        
        std::cout << prev << "不存在！" << std::endl;
        fl.insert_after(before_iter, after);
        return ;
    }
    fl.insert_after(iter, after);
}