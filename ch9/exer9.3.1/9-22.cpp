#include <iostream>
#include <vector>

// insert后，原先指定的mid、iter迭代器都失效

int main()
{
    std::vector<int> iv{1, 1, 1, 1, 1};
    std::vector<int>::iterator iter = iv.begin(),
                                mid = iv.begin() + iv.size() / 2;
    std::vector<int>::size_type original_size = iv.size();

    int some_val = 1, new_eles = 0;
    while (iter != (iv.begin() + new_eles + original_size/2)) {
        if (*iter == some_val) {
            iter = iv.insert(iter, 2 * some_val);
            iter += 2;
            ++new_eles;
        }
        else
            ++iter;
    }
    for (iter = iv.begin(); iter != iv.end(); ++iter)
        std::cout << *iter << " ";
    std::cout << std::endl;
    
    return 0;
}
