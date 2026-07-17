#include <iostream>
#include "Order.h"
#include "MarketTypes.h"


int main() {
    // Create an Order object
    //using namespace std::chrono;
    Order new_order (ActionType::Buy, PriceType::Limit, 100);
    new_order.get_info();



    return 0;
}