#include <iostream>
#include <regex>
#include <string>
#include <set>
#include <algorithm>
using namespace std;
int main()
{
    string pattern("[^c]ei");  
	pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*"; 
    regex r(pattern);
    smatch results;
    string test_str = "receipt freind theif receive albeit neighbor";  
    set<string> right_word{"albeit", "neighsasdwebor"};
    
    for (sregex_iterator it(test_str.cbegin(), test_str.cend(), r), end_it;
            it != end_it; ++it) {
        if (right_word.find(it->str()) != right_word.cend())
            continue;    
        cout << it->str() << endl;
    }

    return 0;
}