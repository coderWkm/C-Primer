#include <iostream>
#include <string>
using namespace std;
string get_full_name(const string &name, const string &prefix, 
                                         const string &suffix)
{
    if (name.empty()) {
        cout << "输入名字为空！" << endl;
        return "";
    }

    string new_name(name);
    // string::iterator iter = new_name.begin();
    // new_name.insert(iter, prefix.cbegin(), prefix.cend());
    // new_name.append(suffix);
    new_name.insert(0, prefix);
    new_name.insert(new_name.size(), suffix);
    return new_name;
}

int main()
{
    string name = "James", pre = "Mr.", suff = "III";
    cout << "new:" << get_full_name(name, pre, suff) << endl;
    
    return 0;
}
