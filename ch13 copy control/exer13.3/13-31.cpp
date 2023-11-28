#include <iostream>
#include "HasPtr.h"
#include <vector>
#include <algorithm>

int main()
{
    std::vector<HasPtr> ptrs;
    ptrs.push_back(HasPtr("aaaa"));   
    ptrs.push_back(HasPtr("tsatqw"));   
    ptrs.push_back(HasPtr("ewtqo"));   
    ptrs.push_back(HasPtr("kosap"));   
    std::sort(ptrs.begin(), ptrs.end());
    for (auto value : ptrs) {
        std::cout << *(value.get_ps()) << " ";
    }
    // tsatqw kosap ewtqo aaaa 
    return 0;
}
