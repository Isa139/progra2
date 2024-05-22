#include "Lib.hpp"
#include "Constants.hpp"


class Party
{
public:
    int size;
    Customer *customers[MAX_CUSTOMERS_PER_TABLE];

    Party(int size, int &customerCounter) : size(size);
};