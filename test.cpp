// Where the function at?!

#include <iostream>
#include "Order.h"
#include "MarketTypes.h"


// Order generate_random_order() {
//     rand
//     Order rand_order (ActionType::Buy, PriceType::Limit, 100);

// }

int main() {
    // Create an Order object
    PriceValue pv;
    pv.stop = 0.5;
    pv.limit = 0.5;
    Order new_order (ActionType::Buy, PriceType::Limit, pv, 100);
    new_order.get_info();
    return 0;
}