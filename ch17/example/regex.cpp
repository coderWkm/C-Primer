#include <iostream>
#include <regex>
#include <string>

int main()
{
    std::string pattern = "[^c]ei";
    pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
    std::smatch result;
    std::regex r(pattern);
    std::string test_str("receipt freind theif receive");
    if (std::regex_search(test_str, result, r))
        std::cout << result.str() << std::endl;
    
    std::cout << "*******************" << std::endl;
    //std::regex r2("[[:alnum:]]+\\.(cpp|cc|cxx)$", std::regex::icase);
    std::regex r2("[[:alnum:]+\\.(cpp|cc|cxx)$", std::regex::icase);
    std::string filename;
    while (std::cin >> filename) {
        try
        {
            if (std::regex_search(filename, result, r2))
                std::cout << result.str() << std::endl;
        }
        catch(std::regex_error e)
        {
            std::cout << e.what() << std::endl;
            std::cout << e.code() << std::endl;
            /**
             * terminate called after throwing an instance of 'std::regex_error'
               what():  Unexpected character in bracket expression.
               没有打印出code的信息？
            */
        }
    }
    return 0;
}