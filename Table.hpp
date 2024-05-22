#include "Lib.hpp"
#include "Constants.hpp"
#include "Utility.hpp"
#include "Party.hpp"
#include "Waiter.hpp"

using namespace std;

class Table
{
private:
    int number;
    int capacity;
    bool occupied;
    Party *currentParty;
    condition_variable cv;
    mutex mtx;
    Waiter *waiter;

public:
    Table(int num, Waiter *waiter) : number(num), capacity(MAX_CUSTOMERS_PER_TABLE), occupied(false), currentParty(nullptr), waiter(waiter) {}
    void simulateEating();
    void assignParty(Party *party);
    void checkAndFreeTable();
    void freeTable();
    bool isOccupied();
    void manageTables(queue<Party *> &customerQueue, mutex &queueMutex);
};