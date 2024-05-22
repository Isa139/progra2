#include "Party.hpp"

Party::Party(int size, int &customerCounter) : size(size) {
    std::string menu[] = {"Cinnamon Rolls", "Apple Pie", "Cookies", "Chocolate Cupcakes", "Donuts", "Croissant", "Brownies", "Carrot Cake", "Caramel Flan", "Banana Muffins"};

    for (int i = 0; i < size; ++i) {
        int choice = rand() % 10;
        std::string selectedMeal = menu[choice];

        customers[i] = new Customer("Customer" + std::to_string(customerCounter++), selectedMeal);
    }
}
