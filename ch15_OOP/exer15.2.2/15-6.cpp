#include "15-5.h"
#include <iostream>

int main()
{
    Quote q("明朝那些事儿", 59.00);
    print_total(std::cout, q, 5);
    Bulk_quote bq("活着", 36.15, 5, 0.7);
    print_total(std::cout, bq, 10);
    return 0;
}
