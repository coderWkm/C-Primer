#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <string>
/*
    首先定义map，读入规则
    读入文件内容，根据map修改
    ps: 此程序有问题；不是将每个单词与空格后的单词建立map，而是每行！
        因此read_file中读取rules文件也要改成getline
*/
void read_file(std::ifstream &in, std::unordered_map<std::string, std::string> &rules);
void print_map(std::unordered_map<std::string, std::string> &m);
void word_convertion(std::ifstream &in, std::unordered_map<std::string, std::string> &rules);

int main()
{
    std::ifstream is("rules.txt"), in_text("texts.txt");
    std::unordered_map<std::string, std::string> rules;
    if (is)
        read_file(is, rules);
    else 
        std::cerr << "打开转换规则文件失败！" << std::endl;
    is.close();

    if (in_text)
        word_convertion(in_text, rules);
    else    
        std::cerr << "打开转换文件失败！" << std::endl;
    
    return 0;
}
// in、out都绑订texts.txt
void word_convertion(std::ifstream &in, std::unordered_map<std::string, std::string> &rules)
{
    std::string line;
    while (std::getline(in, line)) {
        std::istringstream str_in(line);
        std::string word;
        while (str_in >> word) {
            if (rules.find(word) != rules.end())
                std::cout << rules[word] << " ";
            else    
                std::cout << word << " ";
        }
        std::cout << std::endl;
    }
}
void read_file(std::ifstream &in, std::unordered_map<std::string, std::string> &rules)
{
    std::string old_word, new_word;
    while (in >> old_word) {
        in >> new_word;
        rules[old_word] = new_word;
    }
    //std::cout << "规则读取完成！map存储：";
    //print_map(rules);
}
void print_map(std::unordered_map<std::string, std::string> &m)
{
    std::cout << "该map的大小：" << m.size() << "， 成员情况：" << std::endl;
    for (const auto &value:m) {
        std::cout << value.first << "----->"
                  << value.second << std::endl;
    }
}