#include "Basket.hpp"

int main()
{
    Basket item;
    for (auto i = 0; i < 4; ++i)
        // 不少于 2 本打折
        item.add_item(Bulk_quote("978-7-121-15535-2", 100, 2, 0.2));
    for (auto i = 0; i < 6; ++i)
        // 不少于 5 本打折
        item.add_item(Bulk_quote("978-7-121-15535-1", 100, 5, 0.5));
    std::cout << "Total: " << item.total_receipt(std::cout) << std::endl;
    return 0;
}
