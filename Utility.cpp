#include "Utility.hpp"
#include "Constants.hpp"

int delay(int time) {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    int delay = rand() % 6 + 1;
    int totalTime = time + delay;

    return (totalTime <= 0) ? MIN_EATING_TIME : totalTime;
}

int binaryRandom() {
    return (std::rand() % 2 == 0) ? 1 : -1;
}

int randomRange(int min, int max) {
    return min + (std::rand() % (max - min + 1));
}
