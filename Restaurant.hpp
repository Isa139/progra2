#include "Lib.hpp"
#include "Constants.hpp"


using namespace std;


class Restaurant
{
private:
    queue<Party *> customerQueue; // cola de clientes: cada elemento es un puntero a un objeto de la clase Party
    queue<Order> orderQueue;      // cola de órdenes
    Table *tables[TABLE_COUNT];
    mutex queueMutex;      // asegurarse de que ningun otro hilo acceda a la cola en ese momento
    mutex orderQueueMutex; // asegurarse de que ningun otro hilo acceda a la cola de órdenes
    int customerCounter;   // contador de clientes
public:
    Restaurant();
    void addPartyToQueue(Party *party);
    void assignTables();
    void simulation();
    Party *createParty(int size);
};