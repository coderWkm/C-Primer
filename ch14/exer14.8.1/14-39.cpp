#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
class sizeComp {
public:
    sizeComp(size_t n): sz(n) { }
    bool operator()(const std::string &s) {
        return s.size() <= sz;
    } 
private:
    size_t sz;
};
int main()
{
    std::vector<std::string> strs{
        "aaa", "b", "cc", "asdk",
        "weir09kw", "asd", "rel", "dfkbop",
        "fvzsp", "2o0ro", "wekotrpfwqipfgiw",
        "asd120-54921"
    };
    int cnt = 9;
    int shorter = 0, longer = 0;

    auto citer = strs.cbegin();
    while (citer != strs.cend()) {
        citer = std::find_if(citer, strs.cend(),
            sizeComp(cnt)
        );
        if (citer != strs.cend()) {
            ++shorter;
            ++citer;
        }
    }
    std::cout << "长度<9的单词有：" 
                << shorter << "个" << std::endl;
    std::cout << "长度>=10的单词有：" 
                << strs.size() - shorter << "个" << std::endl;
    // temp_sum = 0;
    //++cnt;
    return 0;
}
