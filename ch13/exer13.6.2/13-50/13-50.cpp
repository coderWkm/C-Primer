#include <iostream>
#include <vector>
#include <algorithm>
#include "String.h"
using namespace std;
/*
    输出：
        1. copy constructor -- One
        2. move constructor -- Two
        3. move constructor -- One
        4. move constructor -- Three
        5. move constructor -- Two
        6. move constructor -- One
        7. move constructor -- Four
        8. One Two Three Four
    https://blog.houhaibushihai.me/archives/di-13-zhang#13.49
    回忆一下，默认初始化的 vector 不分配内存空间。当 push_back 发现 vector 空间不足以容纳新元素时，分配新的空间（通常是加倍），将数据移动到新的空间中（由于 String 定义了移动构造函数，这里确实是 “移动” 而非 “拷贝”），然后释放旧空间。

    因此，当插入 s2 时，空间由 1 扩为 2，并将原有元素（One）移动到新空间，对应第三行输出。

    当插入 Three 时，空间由 2 扩为 4，将 Two、One 移动到新空间，产生两次移动构造，对应第五、六两行输出。
*/

int main()
{
    String s1("One"), s2("Two");
    cout << s1 << " " << s2 << endl << endl;
    String s3(s2);
    cout << s1 << " " << s2 << " " << s3 << endl << endl;
    s3 = s1;
    cout << s1 << " " << s2 << " " << s3 << endl << endl;
    s3 = String("Three");
    cout << s1 << " " << s2 << " " << s3 << endl << endl;

    vector<String> svec;
    //svec.reserve(4);
    svec.push_back(s1); // one
    svec.push_back(std::move(s2));  // two one
    svec.push_back(String("Three")); // three one two: 可能与编译器的vector设计有关？
    svec.push_back("Four"); // four
    for_each(svec.begin(), svec.end(), [] (const String &s) { cout << s << " "; });
    cout << endl;
    
    return 0;
}
