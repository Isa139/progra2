#include "Chef.hpp"


int Chef::cookMeal(int preparationTime)
    {
    int calculatePreparationTime(int preparationTime);
    int randomFactor = binaryRandom();
    int prepDelay = delay(preparationTime);
    int randomRangeValue = randomRange(0, prepDelay);

    int calculatedTime = preparationTime + (preparationTime * randomFactor * randomRangeValue);

    if (calculatedTime < MIN_PREP_TIME)
    {
        calculatedTime = MIN_PREP_TIME;
    }
    return calculatedTime;
    }