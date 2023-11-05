#include <iostream>
#include <vector>

int main()
{
    std::vector<int> nums{1};
    if (!nums.empty()) {
        int val = *nums.begin(), val2 = nums.front();
        auto last = nums.end();
        int val3 = *(--last);
        int val4 = nums.back();
        std::cout << "val: " << val << std::endl;
        std::cout << "val2: " << val2 << std::endl;
        std::cout << "val3: " << val3 << std::endl;
        std::cout << "val4: " << val4 << std::endl;
    }
    
    return 0;
}
