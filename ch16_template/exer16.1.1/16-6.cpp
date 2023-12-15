#include <iostream>
template <typename T, size_t N>
const T* begin(const T (&arr)[N]) {   return arr; }
template <typename T, size_t N>
const T* end(const T (&arr)[N]) {  return arr + N; }

int main()
{
    int a[] = {1, 2, 3};
    auto q = end(a);
    for (const int *p = begin(a); p != q; ++p)
        std::cout << *p << " ";
    return 0;
}
