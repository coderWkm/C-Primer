#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>
#include <numeric>
#include <cassert>
#include <fstream>
#include "Sales_data.h"
using namespace std;

typedef tuple<vector<Sales_data>::size_type, vector<Sales_data>::const_iterator, 
            vector<Sales_data>::const_iterator> matches;
vector<matches> findBook(const vector<vector<Sales_data>>&, const string&);
void reportResults(istream&, ostream&, const vector<vector<Sales_data>>&);
vector<Sales_data> build_store(const string &s);

int main(int argc, char **argv)
{
    assert(argc > 1);
	// each element in files holds the transactions for a particular store
	vector<vector<Sales_data>> files;
	for (int cnt = 1; cnt != argc; ++cnt)
		files.push_back(build_store(argv[cnt]));

	ifstream in("findbook.in");  // ISBNs to search for
	reportResults(in, cout, files);
    return 0;
}

vector<matches> findBook(const vector<vector<Sales_data>> &files, const string &book)
{
    vector<matches> ret;
    for (int i = 0; i != files.size(); ++i) {
        auto it = equal_range(files[i].cbegin(), files[i].cend(), book, compareIsbn);  
        if (it.first != it.second) {
            ret.push_back(make_tuple(i, it.first, it.second));
        }     
    }
    return ret;
}
void reportResults(istream &in, ostream &os, const vector<vector<Sales_data>>& files)
{
    string s; 
    while (in >> s) {
        auto found = findBook(files, s);
        if (found.empty()) {
            cout << s << " not found in any stores " << endl;
            continue;
        }
        for (const auto &store : found) {
            os << "store " << get<0>(store) << " sales: "
                << accumulate(get<1>(store), get<2>(store), Sales_data(s))
                << endl;
        }
    }
}
vector<Sales_data> build_store(const string &s)
{
	Sales_data item;
	vector<Sales_data> ret;
	ifstream is(s);
	while (read(is, item))
		ret.push_back(item);
	sort (ret.begin(), ret.end(), compareIsbn);  // need sort for equal_range to work
	return ret;
}