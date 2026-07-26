// Where the function at?!

#include <iostream>
#include "Order.h"
#include "MarketTypes.h"
#include "PriceAction.h"


// Order generate_random_order() {
//     rand
//     Order rand_order (ActionType::Buy, PriceType::Limit, 100);

// }

int main() {
    // Create an Order object
    PriceValue pv;
    pv.stop = 0.5;
    pv.limit = 0.5;

    Order new_order (ActionType::Buy, PriceType::StopLimitOnQuote, pv, 100);
    new_order.get_info();

    PriceAction price_mvmt{};
    std::cout << price_mvmt.new_timestep() << "\n";
    std::cout << price_mvmt.new_timestep() << "\n";
    std::cout << price_mvmt.new_timestep() << "\n";


    return 0;
}