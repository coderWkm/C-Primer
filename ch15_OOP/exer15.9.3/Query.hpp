#ifndef QUERY_H_
#define QUERY_H_
#include "TextQuery.hpp"
#include "QueryResult.hpp"
#include "Query_base.hpp"
class Query {
    friend Query operator~(const Query&);
    friend Query operator&(const Query&, const Query&);
    friend Query operator|(const Query&, const Query&);
public:
    Query(const std::string&);
    QueryResult eval(const TextQuery &t) const 
    {   return q->eval(t); }
    std::string rep() const 
    {
        std::cout << "Query::rep()" << std::endl;
        return q->rep(); 
    }
private:
    Query(std::shared_ptr<Query_base> query) : q(query) 
    {
        std::cout << "Query::Query(std::shared_ptr<Query_base> query)" << std::endl;
    }
    std::shared_ptr<Query_base> q;
};
std::ostream & 
operator<<(std::ostream &os, const Query &query)
{
    std::cout << "operator<<(std::ostream &os, const Query &query)" << std::endl;
    return os << query.rep();
}

TextQuery get_file(int, char **);

bool get_word(std::string &);

bool get_words(std::string &, std::string &);
#endif