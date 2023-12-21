#include <iostream>
#include <string>
#include <regex>
using namespace std;
/**
 * P659下例子
 * valid: (908) 555-1800, substitute: 908.555.1800
*/
int main()
{
    string pattern = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";
    string phone_num, fmt = "$2.$5.$7 "; //书上为了不影响输出效果，加了空格
    regex r(pattern);
    smatch results;
    while (getline(cin, phone_num)) {
        cout << "全部输出：" << regex_replace(phone_num, r, fmt) << endl;
        cout << "输出匹配内容：" << regex_replace(phone_num, r, fmt, std::regex_constants::format_no_copy) << endl;
    }     
    return 0;
}