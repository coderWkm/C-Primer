#include "Query.hpp"
#include "TextQuery.hpp"
#include "QueryResult.hpp"
#include "FourQuery.hpp"
#include <string>
#include <set>
#include <iostream>

using std::set;
using std::string;
using std::cin; using std::cout; using std::cerr;
using std::endl;

/**
 * 编译出现：undefined reference to `vtable for OrQuery'
 * 参考：https://www.douban.com/note/569981079/?_i=1917159CzUX-HX
 * 该问题是由于virtual函数没有定义导致，将
    QueryResult eval(const TextQuery&) const;
    改为
    QueryResult eval(const TextQuery&) const override { }
*/

int main(int argc, char **argv)
{
    // iterate with the user: prompt for a word to find and print results
    while (true) {
        string sought1 = "fiery", sought2 = "bird", sought3 = "wind";
        // find all the occurrences of the requested string
        Query q = Query(sought1) & Query(sought2)
                  | Query(sought3);
        cout << "\nExecuting Query for: " << q << endl;
    }
    return 0;
}
