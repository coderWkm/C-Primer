#include <iostream>
#include <string>
using namespace std;
void replace_string(string &s, const string &oldVal, const string &newVal)
{
    string::iterator iter = s.begin();
    if (s.size() < oldVal.size()) {
        cout << "源字符串太短！" << endl;
        return ;
    }
    while (iter != s.end()) {
        if (oldVal == string(iter, iter+oldVal.size())) {   // P299 顺序容器通用构造器：指定构造器范围
            string::size_type dist = iter - s.cbegin();  // 存储迭代器已经遍历过的位移
            s.replace(iter, iter+oldVal.size(), newVal);   
            iter = s.begin(); // replace后原来的iter已经失效， 需要重新赋值！
            advance(iter, dist + newVal.size());  // 迭代器后移
        }
        else 
            ++iter;
    }
}

int main()
{
    string str1("aasd$* tho wsf thooo dthruas");
    replace_string(str1, "thru", "though");
    cout << "str1: " << str1 << endl;
    
    string str2("aasd$* tho wsf thooo dthruas");
    replace_string(str2, "tho", "though");
    cout << "str2: " << str2 << endl;
    
    return 0;
}
