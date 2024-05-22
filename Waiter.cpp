#include "Waiter.hpp"

void Waiter::takeOrder(Customer *customer)
    {
        lock_guard<mutex> lock(*orderQueueMutex);
        Order order(customer->name, customer->getMeal());
        orderQueue->push(order);
        cout << "Waiter took order from " << customer->name << " for " << customer->getMeal() << endl;
    }
