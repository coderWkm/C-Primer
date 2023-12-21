#include <iostream>
#include <string>
char* connect_liter(const char *str1, const char *str2);
char* connect_str(const std::string &str1, const std::string &str2);

int main()
{
    char *res = connect_liter("aaaa", "bbbb");   
    size_t i = 0;
    while (res[i] != '\0')
        std::cout << res[i++];
    std::cout << std::endl;
    char *another_res = connect_str(std::string("aaaaa"), std::string("bbbbb"));
    i = 0;
    while (another_res[i] != '\0')
        std::cout << another_res[i++];

    return 0;
}

char* connect_str(const std::string &str1, const std::string &str2)
{
    char *res = new char[str1.size() + str2.size() + 1];
    std::string::size_type i, j;
    for (i = 0; i != str1.size(); ++i)
        res[i] = str1[i];
    for (j = 0; j != str2.size(); ++j)
        res[i + j] = str2[j];
    res[i + j] = '\0';
    return res;
}

char* connect_liter(const char *str1, const char *str2)
{
    //const char *tmp1 = str1, *tmp2 = str2;
    size_t len1 = 0, len2 = 0;
    while (*(str1+len1) != '\0')
        ++len1;
    while (*(str2+len2) != '\0')
        ++len2;
    char *res = new char[len1 + len2 + 1]; // 最后存储'\0'
    size_t i;
    for (i = 0; i != len1; ++i) {
        res[i] = str1[i];
    }
    size_t j;
    for (j = 0; j != len2; ++j)
        res[i+j] = str2[j];
    res[i+j] = '\0';
    return res;
}