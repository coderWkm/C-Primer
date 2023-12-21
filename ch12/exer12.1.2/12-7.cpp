#include <iostream>
#include <vector>
#include <iterator>
#include <memory>
std::shared_ptr<std::vector<int>> create_vector();
void save_vector(std::shared_ptr<std::vector<int>> pv);
void print_vector(std::shared_ptr<std::vector<int>> pv);
//std::vector<int>* create_vector();
//void save_vector(std::vector<int> *pv);
//void print_vector(std::vector<int> *pv);

int main()
{
    std::shared_ptr<std::vector<int>> pv = create_vector();
    save_vector(pv);
    print_vector(pv);
    
    return 0;
}
std::shared_ptr<std::vector<int>> create_vector()
{
    //return new std::vector<int>();
    return std::make_shared<std::vector<int>>();
}
void save_vector(std::shared_ptr<std::vector<int>> pv)
{
    int input;
    std::cout << "请输入数据：";
    while (std::cin >> input) {
        pv->push_back(input);
    }
    std::cout << "输入结束！" << std::endl;
}
void print_vector(std::shared_ptr<std::vector<int>> pv)
{
    for (auto citer = (*pv).cbegin(); citer != (*pv).cend();
            ++citer)
        std::cout << *citer << " ";
    std::cout << std::endl;
    //delete pv; // 打印完直接delete
}