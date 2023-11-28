#include <iostream>
#include <vector>
#include "String.h"
#include <algorithm>
using namespace std;
/*
    参考来源：https://blog.houhaibushihai.me/archives/di-13-zhang#13.44
    这里不用考虑char存储'\0'的问题，
        在String类中通过size就可以得到该String的结尾字符，不会溢出
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
    // svec.reserve(4);
    svec.push_back(s1);
    svec.push_back(std::move(s2));
    svec.push_back(String("Three"));
    svec.push_back("Four");
    for_each(svec.begin(), svec.end(), [] (const String &s) { cout << s << " "; });
    cout << endl;

    return 0;
}