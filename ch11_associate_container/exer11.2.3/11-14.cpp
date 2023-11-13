#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <utility>
/*
    程序问题：输入下一户的family_name时，首字母丢失
*/

int main()
{
    std::map<std::string, std::vector<std::string>> home;
    std::string family_name, family_member;
    char quit = 'a';
    std::cout << "输入家庭名称（q退出）:" << std::endl;
    std::vector<std::pair<std::string, std::string>> name2birth;
    while (quit != 'q' && std::cin >> family_name) {
        std::cout << "请输入" << family_name << "的家庭成员姓名、生日：";
        home[family_name] = std::vector<std::string>();
        name2birth.clear();
        std::string birth;
        while (quit != 'q' && std::cin >> family_member >> birth) {
            home[family_name].push_back(family_member);
            name2birth.push_back(std::make_pair(family_name+family_member, birth));
            std::cout << "是否继续输入家庭成员（q退出）："; 
            std::cin >> quit;
        }
        std::cout << "生日情况：";
        for (auto value : name2birth)
            std::cout << value.first << ":" << value.second << std::endl;
        std::cout << "下一户（q退出）："; 
        std::cin >> quit;
    }
    std::cout << "添加结束， 总共有" << home.size() 
              << "户家庭，成员情况：" << std::endl;
    int cnt = 0;
    for (const auto &one_home : home) {
        std::cout << ++cnt << ". " << one_home.first << ": ";
        for (auto citer = one_home.second.cbegin(); 
            citer != one_home.second.cend();
            ++citer)
            std::cout << *citer << " ";
        std::cout << std::endl;
    }
    return 0;
}
