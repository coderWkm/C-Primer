#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>
// P288保存姓名、电话的示例

struct PersonInfo {
    std::string name;
    std::vector<std::string> phones;
};
bool valid(const std::smatch &result)
{
    if (result[1].matched)
        return result[3].matched && 
               (result[4].matched == 0 || result[4].str() == " ");
    else 
        return !result[3].matched && result[4].str() == result[6].str();
}
int main()
{
    std::vector<PersonInfo> people;
    std::string line, word;
    std::ifstream input("info.txt");
    std::string pattern = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";
    std::regex r(pattern);
    std::smatch results;
    if (!input) {
        std::cerr << "文件打开失败..." << std::endl;
    }
    while (getline(input, line)) {
        PersonInfo person;
        std::istringstream read(line);
        read >> person.name;
        while (read >> word)
            person.phones.push_back(word);
        people.push_back(person);
    }

    using people_iter = std::vector<PersonInfo>::const_iterator;
    using phone_iter = std::vector<std::string>::const_iterator;
    //打印：
    std::cout << "共有" << people.size() << "人" << std::endl;
    for (people_iter pe_ptr = people.cbegin();
        pe_ptr != people.cend();
        ++pe_ptr) {
        std::cout << (*pe_ptr).name << "的电话：";
        std::string phone_num;
        for (phone_iter ph_ptr = (*pe_ptr).phones.cbegin();
            ph_ptr != (*pe_ptr).phones.cend();
            ++ph_ptr) {
            phone_num += *ph_ptr + " ";
        }
        std::cout << phone_num << std::endl;
        for (std::sregex_iterator it(phone_num.cbegin(), phone_num.cend(), r), end_it;
                it != end_it; ++it) {
            if (valid(*it))
                std::cout << "valid: " << it->str() << " ";
            else
                std::cout << "invalid: " << it->str() << " ";
        } 
        std::cout << std::endl;
    }

    return 0;
}
