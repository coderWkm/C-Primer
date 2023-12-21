#include <iostream>
#include <string>
#include <regex>
using namespace std;
bool valid(const smatch &result)
{
    if (result[1].matched)
        return result[3].matched && 
               (result[4].matched == 0 || result[4].str() == " ");
    else 
        return !result[3].matched && result[4].str() == result[7].str();
}
int main()
{
    string pattern = "(\\()?(\\d{3})(\\))?([-. ])?([ ]*)?(\\d{3})([-. ])?([ ]*)?(\\d{4})";
    string phone_num;
    regex r(pattern);
    smatch results;
    while (getline(cin, phone_num)) {
        for (sregex_iterator it(phone_num.cbegin(), phone_num.cend(), r), it_end;
                it != it_end; ++it) {
            if (valid(*it))
                cout << "valid: " << it->str() << endl;
            else
                cout << "not valid: " << it->str() << endl;
        } 
    }     
    return 0;
}