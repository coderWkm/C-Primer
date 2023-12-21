#include <iostream>
#include <string>
#include <regex>
/**
 * tx 908.555.1500 (908)5551500
*/
using namespace std;
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
    string phone_num;
    regex r(pattern);
    smatch results;
    while (getline(cin, phone_num)) {
        std::vector<std::string> vs;
        for (sregex_iterator it(phone_num.cbegin(), phone_num.cend(), r), it_end;
                it != it_end; ++it) {
            if (valid(*it))
                vs.push_back(it->str());
        } 
        if (vs.size() == 0) {
            std::cout << "no matched number" << std::endl;
        }
        else if(vs.size() == 1) {
            std::cout << vs[0] << std::endl;
        }
        else if(vs.size() >1) {
            for(int i = 1; i < vs.size(); ++i)
                std::cout << vs[i] << " ";
            std::cout << std::endl;
        }
    }     
    return 0;
}