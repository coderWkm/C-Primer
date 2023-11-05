#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::vector<std::string> str_values{"1e3", "25", "0xa7", "3.88"};
    double sum = 0.0;
    for (auto c_iter = str_values.cbegin(); c_iter != str_values.cend(); ++c_iter)
        sum += stod((*c_iter));
    std::cout << sum << std::endl;

    sum = 0;
    std::vector<double> doubles_str{1e3, 25, 0xa7, 3.88};
    for (auto c_iter = doubles_str.cbegin(); c_iter != doubles_str.cend(); ++c_iter)
        sum += *c_iter;
    std::cout << std::to_string(sum) << std::endl;
    
    return 0;
}
