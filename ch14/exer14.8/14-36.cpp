#include <iostream>
#include <vector>
#include <string>

class GetInput {
public:
    GetInput(std::istream &i = std::cin) : is(i) { }
    std::string operator()() const {
        std::string str;
        std::getline(is, str);
        return is ? str : std::string();
    }

private:
    std::istream &is;
};

int main()
{
    GetInput in;
    std::vector<std::string> strs;
    while (std::cin) {
        //std::cout << in() << std::endl;
        strs.push_back(in());
    }
    std::cout << strs.size();
    for (auto citer = strs.cbegin(); citer != strs.cend(); ++citer)
        std::cout << *citer << std::endl;
    return 0;
}
