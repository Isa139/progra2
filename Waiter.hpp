#ifndef WAITER_HPP
#define WAITER_HPP

#include <queue>   // for std::queue
#include <mutex>   // for std::mutex
#include "Order.hpp"   // assuming Order.hpp defines the Order struct
#include "Customer.hpp" // assuming Customer.hpp defines the Customer class
#include "Constants.hpp" // any relevant constants

using namespace std;

class Waiter
{
private:
    queue<Order> *orderQueue;
    mutex *orderQueueMutex;

public:
    Waiter(queue<Order> *orderQueue, mutex *orderQueueMutex) : orderQueue(orderQueue), orderQueueMutex(orderQueueMutex) {}
    void takeOrder(Customer *customer);
    void checkStock();
    void informOutOfStock();
    void deliverMeal();
};

#endif // WAITER_HPP
