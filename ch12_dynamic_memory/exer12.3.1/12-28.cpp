#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <set>
void runQueries(std::ifstream &infile);

int main()
{
    std::ifstream read("text.txt");
    runQueries(read);
    return 0;
}

void runQueries(std::ifstream &infile)
{
    typedef std::vector<std::string>::size_type line_number;
    std::vector<std::string> text;
    std::set<line_number> line_num;
    std::map<std::string, std::set<line_number>> word2line;
    std::string each_line;
    line_number line_cnt = 0;
    while (std::getline(infile, each_line)) { // 读每一行
        text.push_back(each_line);
        ++line_cnt;
        line_num.insert(line_cnt); // 添加行号
        std::string each_word;
        std::istringstream read_word(each_line); //每行中读单词
        while (read_word >> each_word) {
            //word2line.insert(std::make_pair(each_word, line_num));
            word2line[each_word].insert(line_cnt);
        }
    }
    while (true) {
        std::cout << "输入你要查找的单词（q退出）:";
        std::string s;
        if (!(std::cin >> s) || s == "q") break;
        // 根据map中的second值找到行号，根据行号找到text中的文本行信息
        std::cout << s << " occurs " << word2line[s].size() << " times" << std::endl;
        for (const auto &value : word2line[s]) {
            std::cout << "  (" << "line " << value << ")" << " ";
            std::cout << text[value-1] << std::endl;
        }
        std::cout << s << "查询完毕！" << std::endl;       
    }
}
// 模拟print：从in读书数据，通过out输出
/*
std::ostream &print(std::ostream &out, std::ifstream &in)
{
    
    return out;
}
*/