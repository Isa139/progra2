#ifndef CHEF_HPP
#define CHEF_HPP

#include <queue>
#include <mutex>
#include "Utility.hpp"
#include "Order.hpp"

class Chef {
private:
    std::queue<Order> *orderQueue;
    std::mutex *orderQueueMutex;

public:
    Chef(std::queue<Order> *orderQueue, std::mutex *orderQueueMutex);
    int calculatePreparationTime(int preparationTime);
    void cookMeal(int preparationTime);
};

#endif
