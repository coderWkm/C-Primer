#ifndef TEXTQUERY_H
#define TEXTQUERT_H
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>

class TextQuery{
public:
    TextQuery() = default;
    TextQuery(std::ifstream &read_text): in(read_text) {}
    // P431下的query函数定义
private:
    std::vector<std::string> text;
    std::ifstream &in;
    std::set<int> line;  
    std::map<std::string, std::set<int>> word2line;
};

class QueryResult{
public:
    std::ostream& print(std::ostream &out, TextQuery result); // 第二个参数应该是TextQuery::query的返回值
};
#endif