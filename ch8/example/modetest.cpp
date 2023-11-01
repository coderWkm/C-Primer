#include <iostream>
#include <fstream>

int main()
{
    std::ofstream out;
    out.open("scratchpad"); // 该文件的内容被截断
    out.close();
    out.open("precious", std::ofstream::app); 
    out << "some words in precious by app mode!"; // 追加写入
    out.close()
    
    return 0;
}
