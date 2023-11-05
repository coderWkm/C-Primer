#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    string str("ab2c3d7R4E6"), number("0123456789");
    string char_s("qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM");

    cout << "first version: " << endl;
    for (string::size_type id = 0; 
        (id = str.find_first_of(number, id)) != string::npos; 
        ++id)
        cout << id << " ";
    cout << endl; 
    for (string::size_type id = 0; 
        (id = str.find_first_of(char_s, id)) != string::npos; 
        ++id)
        cout << id << " ";
    cout << endl;

    cout << "first not version: " << endl;
    for (string::size_type id = 0; 
        (id = str.find_first_not_of(char_s, id)) != string::npos; 
        ++id)
        cout << id << " ";
    cout << endl; 
    for (string::size_type id = 0; 
        (id = str.find_first_not_of(number, id)) != string::npos; 
        ++id)
        cout << id << " ";

    return 0;
}
