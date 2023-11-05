#include <iostream>
#include <list>
#include <vector>
/*
    应该使用while循环，因为for每次continue会执行一次++
*/

int main()
{
    int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89};
    std::vector<int> ia1{0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89};
    std::list<int> ia2{0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89};
    
    for (auto viter = ia1.begin(); viter != ia1.end(); ++viter) {
        if ((*viter) % 2) {
            viter = ia1.erase(viter);
            --viter;
            continue;
        }
    }
    std::cout << "vector:" << std::endl;
    for (auto viter = ia1.cbegin(); viter != ia1.cend(); ++viter)
        std::cout << *viter << " ";
    std::cout << std::endl;

    for (auto liter = ia2.begin(); liter != ia2.end(); ++liter) {
        if (!((*liter) % 2)) {
            liter = ia2.erase(liter);
            --liter;
            continue;
        }
    }
    std::cout << "list:" << std::endl;
    for (auto liter = ia2.cbegin(); liter != ia2.cend(); ++liter)
        std::cout << *liter << " ";
    std::cout << std::endl;

    return 0;
}
