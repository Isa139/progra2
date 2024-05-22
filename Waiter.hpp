#ifndef WAITER_HPP
#define WAITER_HPP

#include <queue>
#include <mutex>
#include "Order.hpp"
#include "Customer.hpp"

class Waiter {
private:
    std::queue<Order> *orderQueue;
    std::mutex *orderQueueMutex;

public:
    Waiter(std::queue<Order> *orderQueue, std::mutex *orderQueueMutex);
    void takeOrder(Customer *customer);
    void checkStock();
    void informOutOfStock();
};

#endif
