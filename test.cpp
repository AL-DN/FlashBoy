#include <iostream>
#include "Order.h"

int main() {
    // Create an Order object
    //using namespace std::chrono;
    Order new_order (100, "Limit");
    new_order.get_info();



    return 0;
}