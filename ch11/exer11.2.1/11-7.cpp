#include <iostream>
#include <string>
#include <map>
#include <vector>
/*
    程序问题：输入下一户的family_name时，首字母丢失
*/

int main()
{
    std::map<std::string, std::vector<std::string>> home;
    std::string family_name, family_member;
    char quit = 'a';
    std::cout << "输入家庭名称（q退出）:" << std::endl;
    while (quit != 'q' && std::cin >> family_name) {
        std::cout << "请输入" << family_name << "的家庭成员：";
        /*
        std::vector<std::string> tmp;
            while (quit != 'q' && std::cin >> family_member) {
            tmp.push_back(family_member);
            std::cout << "是否继续输入家庭成员（q退出）："; 
            std::cin >> quit;
        }*/
        home[family_name] = std::vector<std::string>();
        //home[family_name] = tmp;
        while (quit != 'q' && std::cin >> family_member) {
            home[family_name].push_back(family_member);
            std::cout << "是否继续输入家庭成员（q退出）："; 
            std::cin >> quit;
        }
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
