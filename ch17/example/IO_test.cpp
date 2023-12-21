#include <iostream>

int main()
{
    std::cout << "default bool: " << true << " " << false << std::endl;   
    std::cout << "alpha bool: " << std::boolalpha << true << " " << false << std::endl;   
    std::cout << "改变后的cout输出：" << true << std::endl;
    std::cout << std::noboolalpha;
    std::cout << "恢复cout默认输出：" << true << std::endl;

    // 输出整数的8、16进制;
    std::cout << std::uppercase; // X大写，十六进制字符表示
    std::cout << std::showbase; //输出进制
    std::cout << "default: " << 20 << " " << 1024 << std::endl;
    std::cout << "oct: " << std::oct << 20 << " " << 1024 << std::endl;
    std::cout << "hex: " << std::hex << 20 << " " << 1024 << std::endl;
    std::cout << "decimal: " << std::dec << 20 << " " << 1024 << std::endl;
    std::cout << std::uppercase << std::noshowbase; //恢复
    
    return 0;
}