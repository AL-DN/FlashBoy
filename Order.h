// Author: Alden Sahi
// Date: 07/17.2026
// Program Name: Order.h
/* Program Description: 
    Defines a Datatype that properly represents a users request to trade. 
    That optimizes memory to be lightweight and searchable.
*/

#include <cstdint>
#include <chrono>

class Order {
    private:
        bool is_active;
        std::string symbol;
        uint16_t quantity;
        std::string price_type;
        std::chrono::time_point<std::chrono::system_clock> init_time;
        // std::chrono::time_point<std::chrono::system_clock> arrival_time;
        // std::chrono::time_point<std::chrono::system_clock> expiration_date;




    public:
        //Constructor Declaration
        Order(uint16_t quantity, std::string price_type,
            std::chrono::time_point<std::chrono::system_clock> new_init_time = std::chrono::system_clock::now(),
            std::string symbol = "VOO", bool is_active = true);

        // Getters
        void get_info();

        // Setters
        // void set_arrival_time(); // Utilizes Poisson Distribution to set arrival delta.
        // void set_quantity(); // Ensures Bounds of using16_t are not exceeded.


    };