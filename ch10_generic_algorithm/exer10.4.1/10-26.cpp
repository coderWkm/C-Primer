#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <list>

int main()
{
    std::vector<int> origin{1, 2, 2, 3, 4, 4, 5, 6, 6, 6};
    std::list<int> dest1, dest2;
    std::unique_copy(origin.begin(), origin.end(), std::inserter(dest1, dest1.begin()));
    std::cout << "使用inserter的复制结果：";
    for (auto value : dest1)
        std::cout << value << " ";
    std::cout << std::endl;

    std::unique_copy(origin.begin(), origin.end(), std::front_inserter(dest2));
    std::cout << "使用front_inserter的复制结果：";
    std::for_each(dest2.cbegin(), dest2.cend(), [](int i){
        std::cout << i << " ";
    });
    std::cout << std::endl;
    
    return 0;
}
