// Author: Alden Sahi
// Date: 07.17.2026
// Program Name: Order.cpp
/* Program Description: 
    Defines a Datatype that properly represents a users request to trade. 
    That optimizes memory to be lightweight and searchable.
*/

#include <iostream>
#include <cstdint>
#include "Order.h"
#include "MarketTypes.h"

// Constructor Implementation
Order::Order(ActionType new_action_type, PriceType new_price_type, 
    PriceValue new_price_value, uint16_t new_quantity, 
    std::chrono::time_point<std::chrono::system_clock> new_init_time,
    std::string new_symbol, bool new_is_active) {

    action_type = new_action_type;
    price_type = new_price_type;  
    price_value = new_price_value;
    quantity = new_quantity;
    init_time = new_init_time;
    symbol = new_symbol;
    is_active = new_is_active;  

    }

// Getters Implementation
void Order::get_info() {
    std::cout << "Order Details:" << "\n";
    std::cout << "Symbol: " << symbol << "\n";
    std::cout << "Quantity: " << quantity << "\n";
    std::cout << "Price Type: " << to_string(price_type) << "\n";
    to_string(price_type, price_value);
    std::cout << "Action Type: " << to_string(action_type) << "\n";
    std::cout << "Init Time: " << init_time << "\n";
    std::cout << "Is Active: " << (is_active ? "Yes" : "No") << "\n\n";
}


// Setters Implementation