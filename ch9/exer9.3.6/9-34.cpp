#include <iostream>
#include <vector>
//死循环，因为iter一直在原地踏步

//修改后：:
int main()
{
    std::vector<int> vi{1,2,3,4,5};
    auto iter = vi.begin();
    while (iter != vi.end()) {
        if (*iter % 2) {
            iter = vi.insert(iter, *iter);
            iter += 2;
        }
        else
            ++iter;
    }
    for (auto value : vi)
        std::cout << value << " ";
    std::cout << std::endl;
    return 0;
}
