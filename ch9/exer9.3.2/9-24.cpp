#include <iostream>
#include <vector>
#define TEST

int main()
{
    #ifndef TEST
    // 先测试正常的
    std::vector<int> nums1{111, 2, 3};
    std::cout << "at(0):" << nums1.at(0) << std::endl;
    std::cout << "[0]:" << nums1[0] << std::endl;
    std::cout << "front:" << nums1.front() << std::endl;
    std::cout << "begin:" << *nums1.begin() << std::endl;
    #endif

    // 空vector
    #ifdef TEST
    std::vector<int> nums2;
    //std::cout << "at(0):" << nums2.at(0) << std::endl;
    /*
    at(0):terminate called after throwing an instance of 'std::out_of_range'
  what():  vector::_M_range_check: __n (which is 0) >= this->size() (which is 0)
    */

    //std::cout << "[0]:" << nums2[0] << std::endl; 
    /*
    Exception has occurred.
    Segmentation fault
    */
    
    // std::cout << "front:" << nums2.front() << std::endl;
    /*
    Exception has occurred.
    Segmentation fault
    */
    std::cout << "begin:" << *nums2.begin() << std::endl;
    /*
    Exception has occurred.
    Segmentation fault
    */

    #endif

    return 0;
}
