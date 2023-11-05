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
            /*
            string::size_type dist = iter - s.cbegin();  // 存储迭代器已经遍历过的位移
            s.replace(iter, iter+oldVal.size(), newVal);   
            iter = s.begin(); // replace后原来的iter已经失效， 需要重新赋值！
            advance(iter, dist + newVal.size());  // 迭代器后移
            */
           iter = s.erase(iter, iter + oldVal.size()); // 返回删除元素之后的字符的迭代器
           iter = s.insert(iter, newVal.cbegin(), newVal.cend());  // 返回插入的新字符的首元素迭代器
           iter += newVal.size(); // 因此iter还得跳转
        }
        else 
            ++iter;
    }
}

int main()
{
    string s = "tho thru tho!";
    replace_string(s, "thru", "though");
    cout << s << endl;
    
    replace_string(s, "tho", "though");
    cout << s << endl;
    
    replace_string(s, "though", "111");
    cout << s << endl;
    return 0;
}

