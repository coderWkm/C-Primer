#ifndef TEXTQUERY_H
#define TEXTQUERY_H
#include <memory>
using std::shared_ptr;

#include "StrVec.h"
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <map>
using std::map;
#include <set>
using std::set;
#include <fstream>
using std::ifstream;
class QueryResult;
class TextQuery {
public:
    typedef vector<string>::size_type line_no;
    TextQuery(ifstream&);
    QueryResult query(const string&) const;
private:
    shared_ptr<StrVec> file;     // input file
    // maps each word to the set of the lines in which that word appears
    map<string, shared_ptr<set<line_no>>> wm;
    // canonicalizes text: removes punctuation and makes everything lower case
    //static string cleanup_str(const string&);
};
#endif