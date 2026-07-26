// Author: Alden Sahi
// Date: 07.25.2026
// Program Name: PriceAction.cpp
/* Program Description: 
    Defines the PriceAction class that allows market volatility to be simulated using Geometric Brownian Motion. 
    Backbone for Order initalization.
*/

#include "PriceAction.h"
#include <cmath>

    // PriceAction Contructor Definition
    PriceAction::PriceAction (double new_S0, double new_mu, double new_sigma, 
        double new_T, int new_N, double new_spread) {
        S0 = new_S0;
        mu = new_mu;
        sigma = new_sigma; 
        T = new_T;
        N = new_N;
        dt = new_T/new_N;
        spread = new_spread;
        sample_dist.param(std::normal_distribution<double>::param_type(0.0, spread));
        }
    
    
    double PriceAction::new_timestep() {
        // Implements GBM to calculate next price
        double Z = norm_dist(gen);
        double next_S0 = S0 * std::exp((mu - 0.5 * sigma * sigma) * dt + sigma * std::sqrt(dt) * Z);
        S0 = next_S0;
        return S0;
    }

    double PriceAction::sample_price() {
        // Samples S0 at spread stddev, intended to be used when creating orders 
        // so that we can find overlap in orderbook and execute trades.
        return S0 + sample_dist(gen);
    }



