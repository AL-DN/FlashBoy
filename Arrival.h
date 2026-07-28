// Author: Alden Sahi
// Date: 07.25.2026
// Program Name: Arrival.h
// Program Description:
/*  
    - This is a class that enables the creation of arrival delay from Order initializaiton to when
    it would theoretically reach the exhange.
    - Utilizes Possion Distribution where lambda is dynamically sampled from a function based on
        time of day.
*/

#include <random>
#include <chrono>
#include <stdexcept>


class Arrival {
    private:
        double peak_lambda;
        double wavelength;
        double min_lambda;


        // Arrival Dist Setup
        std::mt19937 gen{std::random_device{}()};
        std::poisson_distribution<int> arrival_dist;

    public:
        Arrival(double new_peak_lambda = 3.0, double new_wavelength = 3.0, double new_min_lambda = 1.0);
        double get_norm_time(std::chrono::time_point<std::chrono::system_clock> raw_time = std::chrono::system_clock::now() );
        void set_lambda(double hours_from_open);
        int get_orders_created_during_subinterval();
        void set_time_till_next_order();

};

