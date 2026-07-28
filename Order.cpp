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
    
    // Validate Inputs
    validate_price_value(new_price_type, new_price_value);

    // Assignment
    action_type = new_action_type;
    price_type = new_price_type;  

    // NOTE: Since PriceValue is a union, stop/limit and threshold alias the same
    // bytes at offset 0. A caller can populate an irrelevant member (e.g. set
    // limit on a PriceType::Limit order) and validate_price_value has no way to
    // detect it, since unions carry no runtime tag of which member is "active."
    price_value = new_price_value;
    quantity = new_quantity;
    init_time = new_init_time;
    symbol = new_symbol;
    is_active = new_is_active; 
    arrival_time = new_init_time + Arrival.get_network_latency();

    }

// Getters Implementation
void Order::get_info() {
    std::cout << "Order Details:" << "\n";
    std::cout << "Symbol: " << symbol << "\n";
    std::cout << "Quantity: " << quantity << "\n";
    std::cout << "Action Type: " << to_string(action_type) << "\n";
    std::cout << "Price Type: " << to_string(price_type) << "\n";
    std::cout << to_string(price_type, price_value) << "\n";
    std::cout << "Init Time: " << init_time << "\n";
    std::cout << "Is Active: " << (is_active ? "Yes" : "No") << "\n\n";
}


// Setters Implementation