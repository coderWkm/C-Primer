#include <iostream>
#include <memory>
#include <vector>

int main()
{
    std::vector<int> vi{1,2,3};
    std::allocator<int> alloc;
    auto p = alloc.allocate(vi.size() * 2);  // p的类型 int*
    auto q = std::uninitialized_copy(vi.begin(), vi.end(), p);
    std::uninitialized_fill_n(q, vi.size(), 42);
    for (size_t i = 0; i != 2*vi.size(); ++i)
        std::cout << *(p+i) << " ";
    q += vi.size();
    auto cnt = q - p;
    while (q != p) {
        std::cout << "删除第" << cnt-- << "块内存！" << std::endl;
        alloc.destroy(--q);
    }
    return 0;
}
