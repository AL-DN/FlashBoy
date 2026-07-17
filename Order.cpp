#include "Order.h"
#include <iostream>

// Constructor Implementation
Order::Order(uint16_t new_quantity, std::string new_price_type, std::chrono::time_point<std::chrono::system_clock> new_init_time, std::string new_symbol, bool new_is_active) {
    quantity = new_quantity;
    price_type = new_price_type;
    init_time = new_init_time; // default == std::chrono::system_clock::now()
    symbol = new_symbol; // default == "VOO"
    is_active = new_is_active; // default == true
}

// Getters Implementation
void Order::get_info() {
    std::cout << "Order Details:" << "\n";
    std::cout << "Symbol: " << symbol << "\n";
    std::cout << "Quantity: " << quantity << "\n";
    std::cout << "Price Type: " << price_type << "\n";
    std::cout << "Init Time: " << init_time << "\n";
    std::cout << "Is Active: " << (is_active ? "Yes" : "No") << "\n\n";
}


// Setters Implementation