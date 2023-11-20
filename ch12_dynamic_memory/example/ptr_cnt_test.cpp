#include <iostream>
#include <memory>

int main()
{
    std::shared_ptr<int> p = std::make_shared<int>(42);
    std::cout << "p指向：" << *p << ", 计数器：" 
              << p.use_count() << std::endl;
    auto r = p;
    std::cout << "r指向：" << *r << ", r计数器：" << r.use_count()
              << std::endl
              << "p计数器：" << p.use_count() << std::endl;
    
    return 0;
}
