#include <iostream>
#include <vector>
#include <map>

int main()
{
    std::map<int, int> m;
    m[0] = 1;
    std::cout << "map<int,int> size: " << m.size() << std::endl;
    
    std::vector<int> v;
    std::cout << "vector<int> size: " << v.size() << std::endl;
    v[0] = 1;
    std::cout << "vector<int> size: " << v.size() << std::endl;
    /*
    v[0] = 1 报段错误，v的大小是0，越界访问
    */
    
    return 0;
}
