#include <iostream>
template <typename T, size_t N> 
constexpr int get_size(const T (&arr)[N]) {   return N;   }
int main()
{
    int a[] = {0, 2, 4, 6, 8, 10};
    std::cout << get_size(a) << std::endl;
    return 0;
}
