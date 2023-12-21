#include <iostream>
#include <string>
#include <regex>
using namespace std;
/**
 * P657下例子
 * valid: (908) 555-1800, substitute: 908.555.1800
*/
bool valid(const smatch &result)
{
    if (result[1].matched)
        return result[3].matched && 
               (result[4].matched == 0 || result[4].str() == " ");
    else 
        return !result[3].matched && result[4].str() == result[6].str();
}
int main()
{
    string pattern = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";
    string phone_num, fmt = "$2.$5.$7";
    regex r(pattern);
    smatch results;
    while (getline(cin, phone_num)) {
        for (sregex_iterator it(phone_num.cbegin(), phone_num.cend(), r), it_end;
                it != it_end; ++it) {
            if (valid(*it)) {
                cout << "valid: " << it->str() << ", substitute: "
                     << regex_replace(phone_num, r, fmt) << endl;
            }
            else
                cout << "not valid: " << it->str() << endl;
        } 
    }     
    return 0;
}