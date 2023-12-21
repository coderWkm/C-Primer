#include <iostream>
#include <regex>
#include <string>
using namespace std;
int main()
{
    string pattern("[^c]ei");  
	pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*"; 
    regex r(pattern);
    smatch results;
    string test_str = "receipt freind theif receive";  
    
    for (sregex_iterator it(test_str.cbegin(), test_str.cend(), r), end_it;
            it != end_it; ++it) {
        cout << it->str() << endl;
    }

    return 0;
}