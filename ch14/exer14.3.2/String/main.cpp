#include <iostream>
#include "String.h"
using namespace std;
int main()
{
    String s1("One"), s2("Two");
    String s3(s2);
    if (s1 == s2)
        cout << "s1 == s2" << endl;
    else
        cout << "s1 != s2 " << endl;

    if (s3 == s2)
        cout << "s3 == s2" << endl;
    else
        cout << "s3 != s2 " << endl; 
    
    return 0;
}
