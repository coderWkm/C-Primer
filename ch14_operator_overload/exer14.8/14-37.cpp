#include <iostream>
#include <algorithm>
#include <vector>

class IsEqual {
    int value;

public:
    IsEqual(int v) : value(v) { }
    bool operator()(int elem) { return elem == value; }
};

int main() {
    std::vector<int> ivec = {3, 2, 1, 4, 3, 7, 8, 6};
    std::replace_if(ivec.begin(), ivec.end(), IsEqual(3), 5);
    for (int i : ivec)
        std::cout << i << " ";
    std::cout << std::endl;
}
