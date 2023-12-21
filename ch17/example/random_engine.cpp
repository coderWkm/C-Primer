#include <iostream>
#include <random>
#include <vector>

std::vector<unsigned> goodRandVec();

int main()
{
    std::default_random_engine e;
    std::cout << e.max() << ", " << e.min() << std::endl;
    // 2147483646, 1
    for (size_t i = 0; i != 10; ++i)
        std::cout << e() << " ";
    /**
     * 16807 282475249 1622650073 984943658 1144108930 470211272 101027544 1457850878 1458777923 2007237709 
    */
    std::cout << std::endl;

    // 转换随机范围
    std::uniform_int_distribution<unsigned> u(0, 9);
    for (int i = 0; i != 10; ++i)
        std::cout << u(e) << " ";
    std::cout << std::endl;

    std::vector<unsigned> res = goodRandVec();
    std::vector<unsigned> res2 = goodRandVec();
    std::vector<unsigned> res3 = goodRandVec();
    for (int i = 0; i != res.size(); ++i)
        std::cout << res[i] << " ";
    std::cout << std::endl;
    for (int i = 0; i != res2.size(); ++i)
        std::cout << res2[i] << " ";
    std::cout << std::endl;
    for (int i = 0; i != res3.size(); ++i)
        std::cout << res3[i] << " ";
    std::cout << std::endl;


    return 0;
}
std::vector<unsigned> goodRandVec()
{
    static std::default_random_engine e;
    static std::uniform_int_distribution<unsigned> u(0, 9);
    std::vector<unsigned> ret;
    for (size_t i = 0; i != 10; ++i) 
        ret.push_back(u(e));
    return ret;
}