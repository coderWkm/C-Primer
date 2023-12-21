#include <iostream>
#include <string>
#include <regex>
using namespace std;
/**
 * tx 908.555.1500 (908)5551500
*/
int main()
{
    string pattern = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";
    string phone_num, fmt = "$2.$5.$7 "; 
    regex r(pattern);
    smatch results;
    while (getline(cin, phone_num)) {
        regex_search(phone_num, results, r);
        if (!results.empty())
            cout << results.format(fmt) << endl;
        else
            cout << "no match" << endl;
    }     
    return 0;
}