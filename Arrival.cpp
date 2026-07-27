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

#include "Arrival.h"
#include <iostream>
#include <numbers>
#include <cmath>

Arrival::Arrival(double new_peak_lambda, double new_wavelength, double new_min_lambda) {
    peak_lambda = new_peak_lambda;
    wavelength = new_wavelength;
    min_lambda = new_min_lambda;
}


void Arrival::set_lambda(double hours_from_open) {

    // Computes lambda 
    double precise_lambda = peak_lambda * cos((2*std::numbers::pi / wavelength) * hours_from_open) + (peak_lambda + min_lambda);
    
    // Sets Arrival Distributions Lambda
    std::cout << "Lambda Set: " << std::round(precise_lambda) << "\n";
    arrival_dist.param(std::poisson_distribution<int>::param_type(std::round(precise_lambda)));
}

double Arrival::get_norm_time(std::chrono::time_point<std::chrono::system_clock> utc_time) {
    // NOTE:: Assumes exchange is wherever order is being placed *ENSURE LOCAL TIME IS WHERE EXHANGE IS*
    using namespace std::chrono;

    // Translates UTC to Local Timezone
    zoned_time local_time{current_zone(), utc_time};
    
    // Trancates HH_MM_SS from time 
    auto local_days = floor<days>(local_time.get_local_time());
    
    // REMOVES YYYY_MM_DD from LocalTime to extract HH_MM__SS
    hh_mm_ss time_of_day{local_time.get_local_time() - local_days};
    std::cout << time_of_day << "\n";

    double hours_since_midnight = time_of_day.hours().count()
        + time_of_day.minutes().count() / 60.0
        + time_of_day.seconds().count() / (3600.0);
    
    constexpr double market_open = 9.5;    // 9:30am
    constexpr double market_close = 17.0;  // 5:00pm

    if (hours_since_midnight < market_open || hours_since_midnight > market_close) {
        throw std::invalid_argument("[get_norm_time] utc_time is outside market hours");
    }

    return hours_since_midnight - market_open;

}

double Arrival::get_network_latency() {

    // Ensure Lambda is current
    set_lambda(get_norm_time());

    // NOTE: UNSURE WHAT UNIT IS OUTPUT
    return arrival_dist(gen);
};
