#include <iostream>
#include <numeric>
#include <vector>

int main()
{
    // 10.3
    std::vector<int> nums{1, 2, 3, 4, 5};
    int sum = accumulate(nums.cbegin(), nums.cend(), 0);   
    std::cout << "sum: " << sum << std::endl;

    // 10.4
    std::vector<double> dnums{1.1, 2.2, 3.3};
    double double_sum = accumulate(dnums.cbegin(), dnums.cend(), 0);
    double real = accumulate(dnums.cbegin(), dnums.cend(), 0.0);
    std::cout << "double sum: " << double_sum << std::endl;
    std::cout << "real double sum: " << real << std::endl;
    /*
        double_sum结果是6：看P338的NOTE
    */
    
    return 0;
}
