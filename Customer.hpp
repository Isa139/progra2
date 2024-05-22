#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP

#include "Lib.hpp"
#include "Constants.hpp"

using namespace std;

class Customer {
private:
    string selectedMeal;

public:
    string name;
    char status;

    // Default constructor
    Customer() : name(""), selectedMeal(""), status('S') {}  // Setting default values for name, selectedMeal, and status

    // Parameterized constructor
    Customer(string name, string meal) : name(name), selectedMeal(meal), status('S') {}

    string getMeal();
    void orderMeal();
    void eatMeal(int durationTime);
};

#endif // CUSTOMER_HPP