// Author: Alden Sahi
// Date: 07.22.2026
// Program Name: GBM.h
/* Program Description: 
    Simulates PriceAction using GBM (Geometric Brownian Motion)
    Allows sampling at a δ
*/


#include <random>
#include <cmath>
#include <vector>
#include <iostream>



class PriceAction {
    
    double S0;      // intial stock price
    double mu;      // dift (expected annual return)
    double sigma;   // volatility (annualized)
    double T;       // time horizon in years
    int N;          // number of time steps 
    double dt;       // size of each time step 

    // Intializes N(0,1)


    PriceAction (double new_S0 = 100.0, double mu = 0.05, double sigma = 0.2, double T = 1.0, int N = 252);
    double new_timestep(double new_S0 = 100.0, double mu = 0.05, double sigma = 0.2, double T = 1.0, int N = 252);

};