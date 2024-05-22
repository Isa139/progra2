#include "Lib.hpp"
#include "Constants.hpp"

using namespace std;

class Customer
{
private:
    string selectedMeal; // Plato seleccionado para este cliente
public:
    string name;
    char status;
    // S: Seated
    // O: ordered
    // W: waiting
    // E: eating
    // D: Done
    Customer(string name, string meal) : name(name), selectedMeal(meal) {}
    string getMeal();
    void orderMeal();
    void eatMeal(int durationTime);
};
