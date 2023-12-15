#include <iostream>
#include "StrVec.h"
#include <string>
using std::cout; using std::endl;
int main()
{
    StrVec svec{"one", "piece"};
    cout << "emplace " << svec.size() << endl;
    svec.emplace_back("End");
    svec.emplace_back(3, '!');
    for (std::string *it = svec.begin(); it != svec.end(); ++it)
        cout << *it << " ";
    cout << endl;
    return 0;
}
