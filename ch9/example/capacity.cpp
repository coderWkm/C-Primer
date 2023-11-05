#include <iostream>
#include <vector>

int main()
{
    std::vector<int> ivec;

    std::cout << "ivec size: " << ivec.size()
              << ", capacity: " << ivec.capacity()
              << std::endl;
    for (std::vector<int>::size_type i = 0; i != 24; ++i)
        ivec.push_back(i);
    std::cout << "ivec size: " << ivec.size()
              << ", capacity: " << ivec.capacity()
              << std::endl;

    ivec.reserve(50);
    std::cout << "ivec size: " << ivec.size()
              << ", capacity: " << ivec.capacity()
              << std::endl;
    
    while (ivec.size() != ivec.capacity()) {
        ivec.push_back(0);
    }
    std::cout << "ivec size: " << ivec.size()
              << ", capacity: " << ivec.capacity()
              << std::endl;

    ivec.push_back(25);
    std::cout << "ivec size: " << ivec.size()
              << ", capacity: " << ivec.capacity()
              << std::endl;
    ivec.shrink_to_fit();
    std::cout << "ivec size: " << ivec.size()
              << ", capacity: " << ivec.capacity()
              << std::endl;
    
    ivec.insert(ivec.end(), 12);
    std::cout << "ivec size: " << ivec.size()
              << ", capacity: " << ivec.capacity()
              << std::endl;

    return 0;
}
