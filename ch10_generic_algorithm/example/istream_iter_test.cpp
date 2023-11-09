#include <vector>
#include <iostream>
#include <numeric>
#include <iterator>
/*
    P360下：流迭代器的测试
*/

int main()
{
    std::istream_iterator<int> int_iter(std::cin), end;
    std::cout << std::accumulate(int_iter, end, 0) << std::endl;
    
    return 0;
}
