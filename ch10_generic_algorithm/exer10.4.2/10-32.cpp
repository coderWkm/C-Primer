#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include "Sales_item.h"
#include <numeric>

int main()
{
    std::vector<Sales_item> items;
    Sales_item total;
    std::istream_iterator<Sales_item> is(std::cin), eof;
    while (is != eof) 
        items.push_back(*is++);
    if (items.empty()) {
        std::cerr << "No data?" << std::endl;
        return -1;
    }
    std::sort(items.begin(), items.end(), compareIsbn);
    std::ostream_iterator<Sales_item> output(std::cout, "\n");
    std::cout << "根据isbn排序后：" << std::endl;
    copy(items.cbegin(), items.cend(), output);
    
    // 开始计算
    std::cout << "开始计算：" << std::endl;
    auto iter = items.cbegin();
    while (iter != items.cend()) {
        auto first_item = *iter; 
        auto one_end = std::find_if(iter, items.cend(), [first_item](const Sales_item &value){
            return first_item.isbn() != value.isbn();
        });
        output = std::accumulate(iter, one_end, Sales_item(iter->isbn()));
        iter = one_end;
    }
        
    return 0;
}
