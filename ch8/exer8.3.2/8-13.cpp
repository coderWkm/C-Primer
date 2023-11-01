#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
// P288保存姓名、电话的示例

struct PersonInfo {
    std::string name;
    std::vector<std::string> phones;
};
int main()
{
    std::vector<PersonInfo> people;
    std::string line, word;
    std::ifstream input("info.txt");
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
        for (phone_iter ph_ptr = (*pe_ptr).phones.cbegin();
            ph_ptr != (*pe_ptr).phones.cend();
            ++ph_ptr) {
            std::cout << *ph_ptr << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
