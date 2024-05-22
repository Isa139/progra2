#ifndef ORDER_HPP
#define ORDER_HPP

#include "Lib.hpp"
#include "Constants.hpp"
#include "Utility.hpp"
#include "Customer.hpp"

using namespace std;

struct Order
{
    string customerName;
    string mealName;

    Order(string customerName, string mealName) : customerName(customerName), mealName(mealName) {}
};

#endif // ORDER_HPP
