#include "Waiter.hpp"

Waiter::Waiter(std::queue<Order> *orderQueue, std::mutex *orderQueueMutex)
    : orderQueue(orderQueue), orderQueueMutex(orderQueueMutex) {}

void Waiter::takeOrder(Customer *customer) {
    std::lock_guard<std::mutex> lock(*orderQueueMutex);
    Order order(customer->name, customer->getMeal());
    orderQueue->push(order);
    std::cout << "Waiter took order from " << customer->name << " for " << customer->getMeal() << std::endl;
}

void Waiter::checkStock() {
    // Implementation of stock checking logic
}

void Waiter::informOutOfStock() {
    // Implementation of informing out of stock logic
}
