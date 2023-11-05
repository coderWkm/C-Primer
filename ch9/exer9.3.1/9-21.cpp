#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::vector<std::string> word_vector;
    std::string word;
    std::vector<std::string>::iterator iter = word_vector.begin();
    while (std::cin >> word)
        iter = word_vector.insert(iter, word);
    for (iter = word_vector.begin(); iter != word_vector.end(); ++iter)
        std::cout << *iter << " ";

    return 0;
}