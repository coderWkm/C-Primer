#include <iostream>
#include <memory>
#include <string>
int main()
{
    std::allocator<std::string> alloc_str; // 1. 先声明allocator类
    size_t n = 0;
    std::cout << "想保存几个字符串：";
    std::cin >> n;
    std::string *p_beg = alloc_str.allocate(n); // 2. 分配原始内存
    auto p_end = p_beg;
    std::cout << "请输入字符串：";
    std::string input;
    while (std::cin >> input && p_end != (p_beg + n)) { // 3.根据输入分配每一个内存
        alloc_str.construct(p_end++, input);
        std::cout << *(p_end - 1) << std::endl;
    }
    // 4. 销毁
    while (p_end != p_beg) {
        alloc_str.destroy(--p_end);
    }
    alloc_str.deallocate(p_end, n);
    std::cout << "销毁后，指针p_beg: " << p_beg 
              << ", 指针p_end: " << p_end << std::endl;
    /*
        销毁后，指针p_beg: 0xed1aa0, 指针p_end: 0xed1aa0
        所以虽然deallocate，但是没有将两个指针置为nullptr？
    */
    return 0;
}
