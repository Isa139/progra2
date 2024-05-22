#include "Lib.hpp"
#include "Constants.hpp"

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