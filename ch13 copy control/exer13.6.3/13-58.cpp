#include <iostream>
#include <vector>
#include <algorithm>

class Foo {
    friend void print_data(const Foo &);
public:
    Foo sorted() &&;
    Foo sorted() const &;
private:
    std::vector<int> data{1, 5, 9, -10, 3};
};
int main()
{
    // 13.56
    Foo f1;
    f1.sorted();
    print_data(f1);
    // 为什么没有data的顺序？ 打印结果还是1 5 9 -10 3
    return 0;
}

void print_data(const Foo &f) 
{
    for (auto citer = f.data.cbegin(); 
        citer != f.data.cend();
        ++citer)
        std::cout << *citer << " ";
    std::cout << std::endl;   
}

Foo Foo::sorted() && 
{
    std::cout << "进入右值版本sorted：" << std::endl;
    std::sort(data.begin(), data.end());
    return *this;
}
Foo Foo::sorted() const &
{
    std::cout << "进入左值版本sorted：" << std::endl;
    /*
    Foo ret(*this);
    return ret.sorted();
    重复输出本函数中的输出语句
    */
    return Foo(*this).sorted();
    
}
