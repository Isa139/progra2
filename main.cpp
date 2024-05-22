#include "Restaurant.hpp"
#include "Constants.hpp" // Ensure this is included

void runRestaurant() {
    srand(static_cast<unsigned int>(time(0)));
    Restaurant restaurant;
    std::thread restaurantThread(&Restaurant::threads, &restaurant);

    while (true) {
        int partySize = rand() % 6 + 1;
        restaurant.addPartyToQueue(restaurant.createParty(partySize));
        std::this_thread::sleep_for(std::chrono::seconds(SPAWN_RATE));
    }

    restaurantThread.join();
}

int main() {
    runRestaurant();
    return 0;
}
