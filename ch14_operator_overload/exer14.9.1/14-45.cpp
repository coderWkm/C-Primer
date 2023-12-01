#include <iostream>
#include "Sales_data.h"

int main()
{
    Sales_data life("living", 10, 25.9);
    std::cout << life << std::endl;
    std::cout << std::string(life) << std::endl;
    std::cout << double(life) << std::endl;
    return 0;
}
