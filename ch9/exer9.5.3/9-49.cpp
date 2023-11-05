#include <iostream>
#include <string>
#include <fstream>

using namespace std;
int main()
{
    string file("char.txt");
    ifstream read;
    string max_word, word; // 从文件读入的每个单词、最长的符合条件的单词
    string exclude_a_d("bdfghjklpqty");

    read.open(file);
    if (read) {
        max_word = "";
        while (read >> word) {
            if (word.find_first_of(exclude_a_d) != string::npos) {
                cout << word << "不符合条件" << endl;
                continue;
            }
            cout << word << "符合条件" << endl;
            if (max_word.size() < word.size())
                max_word = word;
        }
    }
    else {
        cerr << "文件打开失败！" << endl;
    }

    cout << "最终的最长单词结果：" << max_word << endl;
        
    return 0;
}
