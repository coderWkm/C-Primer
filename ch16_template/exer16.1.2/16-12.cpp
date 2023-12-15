#include <string>
using std::string;

#include <iostream>
using std::cout; using std::endl;

#include "Blob.h"

int main() {
    Blob<string> b1; // empty Blob
    cout << b1.size() << endl;
    {  // new scope
        string temp[] = {"a", "an", "the"};
        Blob<string> b2(temp, temp + sizeof(temp) / sizeof(*temp));
        b1 = b2;  // b1 and b2 share the same elements
        b2.push_back("about");
        cout << b1.size() << " " << b2.size() << endl;
    } // b2 is destroyed, but the elements it points to must not be destroyed
    cout << b1.size() << endl;
    for (BlobPtr<string> p = b1.begin(); p != b1.end(); ++p)
        cout << *p << endl;

    return 0;
}
