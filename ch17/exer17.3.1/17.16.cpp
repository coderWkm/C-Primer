#include <iostream>
#include <string>
#include <regex>
using namespace std;

int main()
{
    /**
     * 此时只能匹配三个字母的单词
    */
    string name;
    smatch result;
    regex r2("[^c]ei");
    while (cin >> name) {
        if (regex_search(name, result, r2))
            cout << result.str() << endl;
        else
            cout << name << "不匹配" << endl;
    }

    return 0;
}