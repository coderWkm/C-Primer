#include <iostream>
#include <string>

int main()
{
    std::string name("AnnaBelle"), numbers("0123456789");
    std::cout << name.find(numbers) << std::endl; 
    // string::npos ——————> 18446744073709551615
    
    return 0;
}
