#include "Table.hpp"

void Table::simulateEating()
    {
        if (currentParty)
        {
            printf("Table %i is now serving a party of %i customers.\n", number, currentParty->size);
            for (int i = 0; i < currentParty->size; ++i)
            {
                currentParty->customers[i]->status = 'S';
                cout << "Customer " << currentParty->customers[i]->name << "'s status is" << currentParty->customers[i]->status << "\n";
                currentParty->customers[i]->orderMeal(); // cada cliente de la mesa pide su plato
                waiter->takeOrder(currentParty->customers[i]);
                currentParty->customers[i]->status = 'W';
                cout << "Customer " << currentParty->customers[i]->name << "'s status is" << currentParty->customers[i]->status << "\n";
                cout << currentParty->customers[i]->name << " has begun eating.\n";
                currentParty->customers[i]->status = 'E';
                cout << "Customer " << currentParty->customers[i]->name << "'s status is" << currentParty->customers[i]->status << "\n";
                int eatingTime = delay(1);
                printf("They will last %i seconds.\n", eatingTime);
                eatMeal(eatingTime);
                cout << "Customer " << currentParty->customers[i]->name << " is done eating.\n";
                currentParty->customers[i]->status = 'D';
                cout << "Customer " << currentParty->customers[i]->name << "'s status is" << currentParty->customers[i]->status << "\n";
            }
            // this_thread::sleep_for(chrono::seconds(delay(MIN_EATING_TIME)));
            // freeTable();

            thread releaseThread(&Table::freeTable, this); // crear un hilo para liberar la mesa una vez que el grupo haya terminado de comer
            releaseThread.detach();                        // lo hace un hilo independiente
        }
    }

    void Table::assignParty(Party *party)
    {
        lock_guard<mutex> lock(mtx); // crea un objeto lock_guard que bloquea el mutex mtx asociado a la mesa actual
        currentParty = party;        // asigna el party a la mesa
        occupied = true;             // la mesa ahora esta ocupada
        simulateEating();
    }

    void Table::checkAndFreeTable()
    {
        unique_lock<mutex> lock(mtx);
        while (true)
        {
            cv.wait(lock, [this]()
                    {
                for (int i = 0; i < currentParty->size; ++i) {
                    if (currentParty->customers[i]->status != 'D') {
                        return false;
                    }
                }
                return true; });

            freeTable();
            return;
        }
    }

    void Table::freeTable()
    { // libera la mesa
        lock_guard<mutex> lock(mtx);
        occupied = false;
        currentParty = nullptr;
        cout << "Table " << number << " is now free.\n";
    }

     bool Table::isOccupied()
    { // delvuelve el estado ed la mesa
        lock_guard<mutex> lock(mtx);
        return occupied;
    }


    void Table::manageTables(queue<Party *> &customerQueue, mutex &queueMutex)
    { // asignacion de grupos de clientes a las mesas
        while (true)
        {
            Party *party = nullptr;
            {
                lock_guard<mutex> lock(queueMutex);
                if (!customerQueue.empty() && !isOccupied())
                {                                  // verifica disponibilidad de mesa y que existan clientes en la cola
                    party = customerQueue.front(); // primer grupo de clientes de la cola
                    customerQueue.pop();
                }
            }

            if (party)
            { // se asigna el grupo a una mesa
                assignParty(party);
            }
            else
            {
                this_thread::sleep_for(chrono::milliseconds(100)); // si no hay clientes, espera un momento y despues vuelve a revisar
            }
        }
    }