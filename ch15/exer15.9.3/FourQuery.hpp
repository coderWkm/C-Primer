#ifndef WORD_QUERY_H
#define WORD_QUERY_H
#include "Query.hpp"
class WordQuery : public Query_base {
    friend class Query;
    WordQuery(const std::string &s) : query_word(s) 
    {
        std::cout << "WordQuery(const std::string&) -- "
                  << "(" << s << ")" << std::endl;
    }
    QueryResult eval(const TextQuery &t) const 
    {   return t.query(query_word);     }
    std::string rep() const {   return query_word; }
    std::string query_word;
};

class NotQuery : public Query_base {
    friend Query operator~(const Query &);
    NotQuery(const Query &q) : query(q) {}
    std::string rep() const {return "~(" + query.rep() + ")";}
    QueryResult eval(const TextQuery&) const;
    Query query;
};

class BinaryQuery : public Query_base {
protected:
    BinaryQuery(const Query &l, const Query &r, std::string s) :
        lhs(l), rhs(r), opSym(s) 
    {
         std::cout << "BinaryQuery(const Query&, const Query&, std::string) -- "
                  << "(" << l << ", " << r << ", " << s << ")" << std::endl;
    }
    std::string rep() const 
    {
        return "(" + lhs.rep() + " "
                   + rhs.rep() + ")";
    }

    Query lhs, rhs;
    std::string opSym;
};

class AndQuery : public BinaryQuery {
    friend Query operator&(const Query &, const Query &);

    AndQuery(const Query &left, const Query &right) :
            BinaryQuery(left, right, "&") {
        std::cout << "AndQuery(const Query&, const Query&) -- "
                  << "(" << left << ", " << right << ")" << std::endl;
    }

    // concrete class: AndQuery inherits rep and defines the remaining pure virtual
    QueryResult eval(const TextQuery &) const override {}
};

class OrQuery : public BinaryQuery {
    friend Query operator|(const Query &, const Query &);

    OrQuery(const Query &left, const Query &right) :
            BinaryQuery(left, right, "|") {
        std::cout << "OrQuery(const Query&, const Query&) -- "
                  << "(" << left << ", " << right << ")" << std::endl;
    }

    QueryResult eval(const TextQuery &) const override {}
};

inline Query::Query(const std::string &s) : q (new WordQuery(s)) 
{
    std::cout << "Query(const std::string&) -- "
              << "(" << s << ")" << std::endl;
}

inline Query operator~(const Query &operand)
{
    return std::shared_ptr<Query_base>(new NotQuery(operand));
}

inline Query operator&(const Query &lhs, const Query &rhs) {
    return std::shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}

inline Query operator|(const Query &lhs, const Query &rhs) {
    return std::shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}
#endif