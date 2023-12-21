#include <iostream>
#include <bitset>
#include <vector>
int main()
{
    std::vector<unsigned long> bitset{1, 2, 3, 5, 8, 13, 21};
    std::bitset<32> bitvec;
    for (const auto &bit : bitset) {
        bitvec.set(bit, true);
    }

    std::cout << bitvec << std::endl;
    
    return 0;
}