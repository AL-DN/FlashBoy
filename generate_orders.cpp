// Author: Alden Sahi
// Date: 07/28/2026
// Program Name: generate_orders.cpp
/* Program Description: Houses main function, initalizes orders based on simulated trading volume.
*/ 

#include <iostream>
#include <chrono>
#include <thread>

#include "Order.h"
#include "MarketTypes.h"
#include "PriceAction.h"
#include "Arrival.h"



/*     PSUEDOCODE

T = total number of steps

for n...T:
    x = arrivals
    t = time_inteval
    time_btwn_orders = t/x
    PriceAction price;

    for i...x
        start = clock.start()
        while((end-start) < time_btwn_orders) {
            end = clock.capture_timepoint()
        }
        Order order(price);
        orderbook.pass(order);

*/

int main() {

    // Inializes Arrival (Simulate Arrivals)
    const double peak_lambda = 3.0;
    const double wavelength = 3.0;
    const double min_lambda = 1.0; // NOTE: ADD CHECK if min_lambda >0.0 (req for poisson)
    Arrival arrival{peak_lambda, wavelength, min_lambda};
    
    // Initalizes PriceAction (Simulates price movements)
    const double S0 = 100.0;      // intial stock price
    const double mu  = 0.05;      // drift (expected annual return)
    const double sigma = 0.2;   // volatility (annualized)
    const double T = 1.0;       // time horizon in years
    const int N = 252;          // number of time steps 
    const double spread = 0.50;  // stddev of sampling noise around S0
    PriceAction price_action{S0, mu, sigma, T, N, spread};

    // For each time step
    for (int i=0; i<N; i++) {

        // Retrives Lambda based on time, injects into Poisson, and samples -> numOrders
        double numOrders = arrival.get_orders_created_during_subinterval();
        std::chrono::seconds subinterval{1};
        std::cout << "Creating " << numOrders << " orders at timestep " << i << " in subinterval " << subinterval << "\n";

        // OrderGenerator
        for (int j=0; j<numOrders; j++) {

            // Sets Price with some variance to fundamental calculated by GBM
            PriceValue pv;
            pv.threshold = price_action.sample_price();

            // Creates New Order
            Order new_order {ActionType::Buy, PriceType::Limit, pv, 100};
            new_order.get_info();
            std::this_thread::sleep_for(subinterval/numOrders);
            std::cout << "\n[Slept For: " << (subinterval/numOrders) << "]\n";
        }

        // Calculates New Price
        price_action.new_timestep();
        break;
    }

    return 0;
}

