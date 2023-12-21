#include <iostream>
#include <algorithm>
#include <vector>
#include "Sales_data.h"

int main()
{
    std::vector<Sales_data> sales_items{
        Sales_data("0-201-78345-X"),
        Sales_data("0-201-78345-X"),
        Sales_data("0-201-78345-B", 100, 128, 49),
        Sales_data("0-201-78345-A"),
        Sales_data("0-201-78345-C"),
        Sales_data("0-201-78345-A"),
        Sales_data("0-201-78345-a"),
    };
    std::sort(sales_items.begin(), sales_items.end(), compareIsbn);
    for (const auto &element : sales_items)
        std::cout << element.isbn() << std::endl;
    
    return 0;
}
