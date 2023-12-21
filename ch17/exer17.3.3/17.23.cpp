#include <iostream>
#include <string>
#include <regex>
using namespace std;
bool valid(const smatch &s)
{
    if (s[3].matched)
        return s[1].matched;
    return s[1].matched;
}
int main()
{
    string pattern = "(\\d{5})?(-)?(\\d{4})";
    regex r(pattern);
    smatch s;
    string num;
    while (cin >> num) {
        for (sregex_iterator it(num.cbegin(), num.cend(), r), it_end;
                it != it_end; ++it) {
            if (valid(*it))
                cout << "valid: " << it->str() << endl;
            else
                cout << "invalid: " << it->str() << endl;
        }
    }
    return 0;
}