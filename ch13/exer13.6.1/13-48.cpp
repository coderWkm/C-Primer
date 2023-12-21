#include <iostream>
#include <vector>
#include <algorithm>
#include "..\exer13.5\13-44\String.h"
using namespace std;

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
    // ？
    svec.push_back(s1); // one
    svec.push_back(std::move(s2));  // two one
    svec.push_back(String("Three")); // three two one 
    svec.push_back("Four"); // four
    for_each(svec.begin(), svec.end(), [] (const String &s) { cout << s << " "; });
    cout << endl;
    
    return 0;
}
