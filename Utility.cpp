#include "Utility.hpp"

int binaryRandom()
{
    if (std::rand() % 2 == 0)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

int randomRange(int min, int max)
{
    return min + (std::rand() % (max - min + 1));
}

void eatMeal(int eatingTime)
{
    int realTime = delay(eatingTime);
    std::this_thread::sleep_for(std::chrono::seconds(realTime));
}

int delay(int time)
{ // tiempo aleatorio para preparacion de comida y liberacion de mesa
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    int delay = rand() % 6 + 1;
    int totalTime = time + delay;

    if (totalTime <= 0)
    {
        return MIN_EATING_TIME;
    }
    else
    {
        return totalTime;
    }
}

void runRestaurant()
{ // simulacion general del restaurante
    srand(static_cast<unsigned int>(time(0)));
    Restaurant restaurant;
    thread restaurantThread(&Restaurant::simulation, &restaurant);

    // simular la llegada de grupos de clientes al restaurante
    while (true)
    {
        int partySize = rand() % 6 + 1;
        restaurant.addPartyToQueue(restaurant.createParty(partySize));
        this_thread::sleep_for(chrono::seconds(SPAWN_RATE));
    }

    restaurantThread.join();
}
