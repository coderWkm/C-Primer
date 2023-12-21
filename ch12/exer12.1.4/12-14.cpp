#include <iostream>
#include <memory>
struct destination {};
struct connection {};
void end_connection(connection *p);
connection connect(destination *dest) 
{
    std::cout << "打开连接dest" << std::endl;
    return connection();
}
void disconnect(connection con)
{
    std::cout << "关闭connect" << std::endl;
}
void f(destination &d) 
{
    connection c = connect(&d);
    std::shared_ptr<connection> p(&c, end_connection); // deleter
    std::cout << "通过shared_ptr：p对连接处理。。。。" << std::endl;
}
void end_connection(connection *p)
{
    std::cout << "断开连接操作：";
    disconnect(*p);
}
int main()
{
    destination d;
    f(d);  
    return 0;
}
