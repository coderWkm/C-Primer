#include <iostream>
#include <string>
#include <regex>
using namespace std;

int main()
{
    string name;
    string pattern = "[^c]ei";
    pattern = "[[:alnum:]]*" + pattern + "[[:alnum:]]*";
    smatch result;
    regex r(pattern);
    while (cin >> name) {
        if (regex_search(name, result, r))
            cout << result.str() << endl;
        else
            cout << name << "不匹配" << endl;
    }

    return 0;
}