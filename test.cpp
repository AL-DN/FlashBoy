// Where the function at?!

#include <iostream>
#include "Order.h"
#include "MarketTypes.h"
#include "PriceAction.h"
#include "Arrival.h"
#include <chrono>


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
    std::cout << std::to_string(price_mvmt.sample_price()) << "\n";
    std::cout << std::to_string(price_mvmt.sample_price()) << "\n";
    std::cout << std::to_string(price_mvmt.sample_price()) << "\n";
    std::cout << std::to_string(price_mvmt.sample_price()) << "\n";
    std::cout << std::to_string(price_mvmt.sample_price()) << "\n";
    std::cout << std::to_string(price_mvmt.sample_price()) << "\n";

    Arrival arrival{2.0, 2.0};
    std::chrono::time_point< std::chrono::system_clock> nw = std::chrono::system_clock::now();
    std::cout << std::to_string(arrival.get_norm_time(nw)) << "\n";
    return 0;
}

