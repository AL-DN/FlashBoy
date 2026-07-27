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

Arrival::Arrival(double new_peak_lambda, double new_wavelength) {
    peak_lambda = new_peak_lambda;
    wavelength = new_wavelength;
}

double Arrival::get_norm_time(std::chrono::time_point<std::chrono::system_clock> raw_time) {
    // NOTE:: Assumes exchange is wherever order is being placed
    using namespace std::chrono;

    zoned_time local_time{current_zone(), raw_time};
    auto local_days = floor<days>(local_time.get_local_time());
    hh_mm_ss time_of_day{local_time.get_local_time() - local_days};

    double hours_since_midnight = time_of_day.hours().count()
        + time_of_day.minutes().count() / 60.0
        + time_of_day.seconds().count() / (3600.0);
    
    constexpr double market_open = 9.5;    // 9:30am
    constexpr double market_close = 17.0;  // 5:00pm

    if (hours_since_midnight < market_open || hours_since_midnight > market_close) {
        throw std::invalid_argument("[get_norm_time] raw_time is outside market hours");
    }

    return hours_since_midnight - market_open;


}