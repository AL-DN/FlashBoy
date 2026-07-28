// Author: Alden Sahi
// Date: 07.17.2026
// Program Name: Order.h
/* Program Description: 
    Declares an Order Datatype that properly represents a users request to trade. 
    Optimized to be lightweight and quickly searched.
*/

#include <cstdint>
#include <chrono>
#include "MarketTypes.h"
// #include "Arrival.h"

class Order {
    private:
        bool is_active;
        std::string symbol;
        ActionType action_type;
        PriceType price_type;
        PriceValue price_value;
        uint16_t quantity;
        std::chrono::time_point<std::chrono::system_clock> init_time;


        // Arrival Time
        double peak_lambda;
        double min_lambda;
        double wavelength;
        
        // Arrival arrival_generator{};
        // std::chrono::time_point<std::chrono::system_clock> arrival_time;
        // std::chrono::time_point<std::chrono::system_clock> expiration_date;

    public:
        //Constructor Declaration
        Order(ActionType new_action_type, PriceType new_price_type, 
            PriceValue new_price_value, uint16_t new_quantity, 
            std::chrono::time_point<std::chrono::system_clock> new_init_time = std::chrono::system_clock::now(),
            std::string new_symbol = "VOO", bool new_is_active = true);


        // Getters
        void get_info();

        // Setters
        // void set_arrival_time(); // Utilizes Poisson Distribution to set arrival delta.
        // void set_quantity(); // Ensures Bounds of using16_t are not exceeded.


    }; 