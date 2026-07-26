// Author: Alden Sahi
// Date: 07.22.2026
// Program Name: GBM.h
/* Program Description: 
    Simulates PriceAction using GBM (Geometric Brownian Motion)
    Allows sampling at a δ
*/


#include <random>
#include <iostream>



class PriceAction {
    private:
        double S0;      // intial stock price
        double mu;      // drift (expected annual return)
        double sigma;   // volatility (annualized)
        double T;       // time horizon in years
        int N;          // number of time steps 
        double dt;       // size of each time step 
        double spread;  // stddev of sampling noise around S0

        std::mt19937 gen{std::random_device{}()};
        std::normal_distribution<double> norm_dist{0.0, 1.0};
        std::normal_distribution<double> sample_dist;

    public:
        PriceAction (double new_S0 = 100.0, double new_mu = 0.05, double sigma = 0.2, double T = 1.0, int N = 252, double new_spread = 0.50);
        double new_timestep();
        double sample_price();
}