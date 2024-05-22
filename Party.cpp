#ifndef PARTY_HPP
#define PARTY_HPP

#include "Lib.hpp"
#include "Constants.hpp"
#include "Customer.hpp"

class Party {
public:
    int size;
    Customer* customers[MAX_CUSTOMERS_PER_TABLE];

    Party(int size, int &customerCounter) : size(size) {
        for (int i = 0; i < size && i < MAX_CUSTOMERS_PER_TABLE; ++i) {
            customers[i] = new Customer();
            customers[i]->name = "Customer " + std::to_string(customerCounter++);
        }
    }

    ~Party() {
        for (int i = 0; i < size && i < MAX_CUSTOMERS_PER_TABLE; ++i) {
            delete customers[i];
        }
    }
};

#endif // PARTY_HPP