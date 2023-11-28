#include <iostream>
#include <vector>

struct X {
    X() {std::cout << "构造函数：X()" << std::endl;}
    X(const X &) {std::cout << "拷贝构造函数：X(const X &)" << std::endl;}
    X& operator=(const X &value) 
    { 
        std::cout << "拷贝赋值运算符：opeartor=(const X &)" << std::endl;
        return *this;
    }
    ~X() {std::cout << "析构函数：~X()" << std::endl;}
};

void f1(X x) { std::cout << "非引用传参" << std::endl;}
void f2(X &x) { std::cout << "引用传参" << std::endl;}

int main()
{
    X a;  // X()

    // 拷贝构造函数
    X b(a); // 拷贝构造函数：X(const X &)

    // 传参
    f1(a);   // ！！！！！形参的拷贝和销毁
    // 拷贝构造函数：X(const X &) 
    // 非引用传参
    // 析构函数：~X()

    f2(a);  //！！！！！引用是绑定了实参的别名，没有拷贝 
    // 引用传参

    // 动态分配
    X *p_x = new X; // 构造函数：X()
    
    // 拷贝赋值运算符和赋值
    X c = a;  // 拷贝构造函数：X(const X &)
    c = b;  // 拷贝赋值运算符：opeartor=(const X &)

    //在vector中存放a、b、c
    std::vector<X> x_array;
    x_array.push_back(a); // 拷贝构造函数：X(const X &)

    delete p_x; // 析构函数：~X()

    /*
    析构函数：~X()： 先销毁x_array, 会调用其中唯一一个成员，a的拷贝，的析构函数
    析构函数：~X()： 销毁c
    析构函数：~X()： 销毁b
    析构函数：~X()： 销毁a
    */

    return 0;
}
