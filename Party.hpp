#ifndef PARTY_HPP
#define PARTY_HPP

#include "Lib.hpp"
#include "Constants.hpp"
#include "Customer.hpp" // Include the header file for the Customer class

class Party {
public:
    int size;
    Customer* customers[MAX_CUSTOMERS_PER_TABLE];

    Party(int size, int &customerCounter) : size(size) {
        // Initialize customers array or any other initialization if necessary
        for (int i = 0; i < size && i < MAX_CUSTOMERS_PER_TABLE; ++i) {
            customers[i] = new Customer(); // Example initialization; adjust as necessary
            // You might want to do something with customerCounter here if needed
        }
    }

    ~Party() {
        // Clean up allocated memory
        for (int i = 0; i < size && i < MAX_CUSTOMERS_PER_TABLE; ++i) {
            delete customers[i];
        }
    }
};

#endif // PARTY_HPP
