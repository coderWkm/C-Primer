#include <iostream>
#include "15-11.h"

int main()
{
    Quote q("booka", 15);
    q.Debug();
    Bulk_quote bq("bookb", 20, 5, 0.7);
    bq.Debug();
    return 0;
}
