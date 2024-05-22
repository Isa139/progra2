#include "Customer.hpp"

string Customer::getMeal()
    {
        return selectedMeal;
    }

void Customer::orderMeal()
    {
        // imprime el plato elegido por el cliente
        cout << " -" << name << " ordered: " << selectedMeal << endl;
    }
