#include <iostream>
#include <regex>
#include <string>
using namespace std;

int main()
{   
    std::regex r("[[:alnum:]]+\\.(cpp|cc|cxx)$", std::regex::icase);
    //smatch result;
    cmatch result;
    if (regex_search("myfile.cpp", result, r))
        cout << result.str() << endl;
    
    return 0;
}