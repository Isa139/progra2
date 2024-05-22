#include "Chef.hpp"
#include "Constants.hpp" // Ensure this is included
#include "Utility.hpp" // Ensure this is included if delay(), binaryRandom(), randomRange() are defined in Utilities
#include <thread>         // Ensure this is included for std::this_thread::sleep_for
#include <chrono>   
#include <iostream>

Chef::Chef(std::queue<Order> *orderQueue, std::mutex *orderQueueMutex)
    : orderQueue(orderQueue), orderQueueMutex(orderQueueMutex) {}

int Chef::calculatePreparationTime(int preparationTime) {
    int randomFactor = binaryRandom();
    int prepDelay = delay(preparationTime);
    int randomRangeValue = randomRange(0, prepDelay);

    int calculatedTime = preparationTime + (preparationTime * randomFactor * randomRangeValue);
    if (calculatedTime < MIN_PREP_TIME) {
        calculatedTime = MIN_PREP_TIME;
    }
    return calculatedTime;
}

void Chef::cookMeal(int preparationTime) {
    while (true) {
        Order order;
        {
            std::lock_guard<std::mutex> lock(*orderQueueMutex);
            if (orderQueue->empty()) {
                break;
            }
            order = orderQueue->front();
            orderQueue->pop();
        }

        int cookingTime = calculatePreparationTime(preparationTime);

        std::cout << "Chef is preparing " << order.mealName << " for " << order.customerName << " Cooking time: " << cookingTime << " seconds " << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(cookingTime));
        std::cout << "Chef finished preparing " << order.mealName << " for " << order.customerName << "." << std::endl;
    }
}
