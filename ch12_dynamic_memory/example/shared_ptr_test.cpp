#include <iostream>
#include <memory>
#include <string>

int main()
{
    std::shared_ptr<int> p1 = std::make_shared<int>();
    std::cout << "p1指向：" << *p1 << std::endl;
    std::shared_ptr<std::string> p2 = std::make_shared<std::string>(10, '9');
    std::cout << "p2指向：" << *p2 << std::endl;
    std::shared_ptr<int> p3 = std::make_shared<int>(10);
    std::cout << "p3指向：" << *p3 << std::endl;
    return 0;
}
