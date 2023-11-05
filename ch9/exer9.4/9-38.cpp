#include <iostream>
#include <vector>

//翻倍增长capacity
int main()
{
    std::vector<int> ivec;
    std::cout << "ivec size: " << ivec.size()
              << ", capacity: " << ivec.capacity()
              << std::endl;

    ivec.push_back(1);
    std::cout << "ivec size: " << ivec.size()
              << ", capacity: " << ivec.capacity()
              << std::endl;
    
    ivec.push_back(1);
    std::cout << "ivec size: " << ivec.size()
              << ", capacity: " << ivec.capacity()
              << std::endl;

    ivec.push_back(1);
    std::cout << "ivec size: " << ivec.size()
              << ", capacity: " << ivec.capacity()
              << std::endl;

    ivec.push_back(1);
    std::cout << "ivec size: " << ivec.size()
              << ", capacity: " << ivec.capacity()
              << std::endl;
    ivec.push_back(1);
    std::cout << "ivec size: " << ivec.size()
              << ", capacity: " << ivec.capacity()
              << std::endl;
    ivec.push_back(1);
    std::cout << "ivec size: " << ivec.size()
              << ", capacity: " << ivec.capacity()
              << std::endl;
    ivec.push_back(1);
    std::cout << "ivec size: " << ivec.size()
              << ", capacity: " << ivec.capacity()
              << std::endl;
    ivec.push_back(1);
    std::cout << "ivec size: " << ivec.size()
              << ", capacity: " << ivec.capacity()
              << std::endl;
    
    ivec.push_back(1);
    std::cout << "ivec size: " << ivec.size()
              << ", capacity: " << ivec.capacity()
              << std::endl;

    return 0;
}
