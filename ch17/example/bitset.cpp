#include <iostream>
#include <bitset>

int main()
{
    std::bitset<32> bitvec(1U);
    bool is_set = bitvec.any();
    std::cout << "bitvec is_set: " << is_set << std::endl;  
    bool is_no_set = bitvec.none();
    std::cout << "bitvec is_no_set: " << is_no_set << std::endl;  
    bool all_set = bitvec.all();
    std::cout << "bitvec all_set: " << all_set << std::endl;  
    size_t onBits = bitvec.count();
    std::cout << "bitvec onBits: " << onBits << std::endl;  
    size_t sz = bitvec.size();
    std::cout << "bitvec sz: " << sz << std::endl;  
    std::cout << "bitvec: ";
    for (size_t i = 0; i != bitvec.size(); i++)
        std::cout << bitvec[i];

    std::cout << std::endl;
    bitvec.flip();
    std::cout << bitvec.count() << std::endl;

    bitvec.reset();
    std::cout << bitvec.count() << std::endl;

    bitvec.set();
    std::cout << bitvec.count() << std::endl;
    std::cout << "*****************" << std::endl;

    std::bitset<32> bitvec4("1100");
    for (size_t i = 0; i != bitvec4.size(); i++)
        std::cout << bitvec4[i];
    std::cout << std::endl;

    std::bitset<128> bitvec3(~0ULL);
    auto ulong = bitvec3.to_ullong();
    std::cout << ulong << std::endl;
    
    std::cout << "*****************" << std::endl;
    std::cout << "bitset读取：";
    std::bitset<16> bits;
    std::cin >> bits;
    std::cout << bits << std::endl;

    return 0;
}