#include <iostream>
#include <list>
#include <forward_list>
#define LIST
#define FLIST

void print_info(const std::list<int> &values);
void print_info(const std::forward_list<int> &values);

int main()
{
    std::list<int> int_list{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::forward_list<int> int_flist{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    #ifdef LIST
    auto list_iter = int_list.begin();
    while (list_iter != int_list.end()) {
        if (*list_iter % 2) {
            list_iter = int_list.insert(list_iter, *list_iter);
            ++list_iter;
            ++list_iter;
        }
        else {
            list_iter = int_list.erase(list_iter);
         }
    }
    print_info(int_list);
    #endif
    
    #ifdef FLIST
    auto flist_iter = int_flist.begin();
    while (flist_iter != int_flist.end()) {
        if (*flist_iter % 2) {
            flist_iter = int_flist.insert_after(flist_iter, *flist_iter);
            //++flist_iter;
            ++flist_iter;
        }
        else {
            flist_iter = int_flist.erase_after(flist_iter);
         }
    }
    print_info(int_flist);
    #endif
    
    return 0;
}

void print_info(const std::list<int> &values)
{
    std::cout << "有" << values.size() << "个元素：";
    for (auto item : values)
        std::cout << item << " ";
    std::cout << std::endl;
    
}
void print_info(const std::forward_list<int> &values)
{
    // forward_list 没有size成员
    //std::cout << "有" << values.size() << "个元素：";
    for (auto item : values)
        std::cout << item << " ";
    std::cout << std::endl;
    
}