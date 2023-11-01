#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    string filename = "..\\example\\file1.txt";
    vector<string> file_content;
    ifstream file_reader(filename, ifstream::in);
    if (file_reader) {
        string tmp;
        while (getline(file_reader, tmp)) { // 从文件中读取一行
            file_content.push_back(tmp);
        }
    }
    file_reader.close();

    vector<string>::const_iterator iter = file_content.cbegin();
    while (iter != file_content.cend()) {
        istringstream line_str(*iter);
        string tmp;
        while (line_str >> tmp)
            cout << tmp << " ";
        cout << endl;
        ++iter;
    }
    return 0;
}
