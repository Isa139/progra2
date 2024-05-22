#ifndef RESTAURANT_HPP
#define RESTAURANT_HPP

#include <queue>       // for std::queue
#include <mutex>       // for std::mutex
#include "Party.hpp"   // assuming Party.hpp defines the Party class
#include "Order.hpp"   // assuming Order.hpp defines the Order struct
#include "Table.hpp"   // assuming Table.hpp defines the Table class
#include "Constants.hpp" // assuming Constants.hpp defines TABLE_COUNT

using namespace std;

class Restaurant
{
private:
    queue<Party *> customerQueue; // queue of customers, each element is a pointer to a Party object
    queue<Order> orderQueue;      // queue of orders
    Table *tables[TABLE_COUNT];   // array of pointers to Table objects
    mutex queueMutex;             // ensure no other thread accesses the queue at the same time
    mutex orderQueueMutex;        // ensure no other thread accesses the order queue at the same time
    int customerCounter;          // customer counter

public:
    Restaurant();                      // constructor
    void addPartyToQueue(Party *party); // add a party to the customer queue
    void assignTables();                // assign tables to parties
    void simulation();                  // start the restaurant simulation
    Party *createParty(int size);       // create a new party
};

#endif // RESTAURANT_HPP
