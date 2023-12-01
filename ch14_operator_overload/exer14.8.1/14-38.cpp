#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
class sizeEqual {
public:
    sizeEqual(size_t n): sz(n) { }
    bool operator()(const std::string &s) {
        return s.size() == sz;
    } 
private:
    size_t sz;
};
int main()
{
    std::vector<std::string> strs{
        "aaa", "b", "cc", "asdk",
        "weir09kw", "asd", "rel", "dfkbop",
        "fvzsp", "2o0ro"
    };
    int cnt = 1;
    int temp_sum = 0;
    while (cnt <= 10) {
        auto citer = strs.cbegin();
        while (citer != strs.cend()) {
            citer = std::find_if(citer, strs.cend(),
                sizeEqual(cnt)
            );
            if (citer != strs.cend()) {
                ++temp_sum;
                ++citer;
            }
        }
        std::cout << "长度为" << cnt << "的单词有：" 
                  << temp_sum << "个" << std::endl;
        temp_sum = 0;
        ++cnt;
    }
    return 0;
}
