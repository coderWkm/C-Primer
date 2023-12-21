#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std::placeholders;
int main()
{
    int n;
    std::cin >> n;
    std::vector<int> nums{1,2,4,5,10};
    std::modulus<int> mod_2;
    auto it = [&](int i){return !mod_2(n, i); };
    auto is_div = std::all_of(nums.begin(), nums.end(), it);
    std::cout << (is_div ? "均可被整除" : "不可被整除") << std::endl;
    return 0;
}
