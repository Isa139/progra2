#include "Restaurant.hpp"
using namespace std;

Restaurant::Restaurant()
{                        // constructor: inicializar los obj table del restaurante
        customerCounter = 1; // inicializar contador en 1
        for (int i = 0; i < TABLE_COUNT; ++i)
        {
            tables[i] = new Table(i + 1, new Waiter(&orderQueue, &orderQueueMutex));
        }
}

void Restaurant::addPartyToQueue(Party *party)
{
        lock_guard<mutex> lock(queueMutex);
        customerQueue.push(party); // coloca al grupo de clientes al final de la cola
}

void Restaurant::assignTables()
    {
        while (true)
        {
            for (int i = 0; i < TABLE_COUNT; ++i)
            {
                if (!tables[i]->isOccupied())
                { // itera sobre las mesas disponibles
                    Party *party = nullptr;
                    {
                        lock_guard<mutex> lock(queueMutex);
                        if (!customerQueue.empty())
                        {
                            party = customerQueue.front(); // primer grupo en la cola para ser atentido
                            customerQueue.pop();           // eliminar de la cola
                        }
                    }
                    if (party)
                    {
                        tables[i]->assignParty(party); // asignar a la mesa
                    }
                }
            }
            this_thread::sleep_for(chrono::milliseconds(100));
        }
    }

void Restaurant::simulation() 
{                                     // inicia la simulacion del restaurante
        thread tableThreads[TABLE_COUNT]; // arreglo de hilos
        for (int i = 0; i < TABLE_COUNT; ++i)
        { // crear un hilo por mesa
            tableThreads[i] = thread(&Table::manageTables, tables[i], ref(customerQueue), ref(queueMutex));
        }

        for (int i = 0; i < TABLE_COUNT; ++i)
        { // permite que los hilos se ejecuten de forma independiente al hilo principal del programa
            tableThreads[i].detach();
        }

        assignTables();
}

Party Restaurant::*createParty(int size)
    {
        return new Party(size, customerCounter);
    }
