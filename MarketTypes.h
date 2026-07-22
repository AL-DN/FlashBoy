// Author: Alden Sahi
// Date: 07.17.2026
// Program Name: MarketTypes.h
// Program Description:
/*  
    These datatypes originally had a fixed number of values. We can:
    1. Reduce memory footprint by using enum to convert to 8 bit integer ( # of values < 256)
    2. Ensures Correctness of logic by enforcing type ( needs to be statically casted)
    3. Increases String Comparison O(n) -> O(1)
*/

#pragma once
#include <cstdint>
#include <string>

union PriceValue {
    double threshold;           // Utilized by StopOnQuote, Limit, TrailingStopDollar, TrailingStopPercent
    struct {                    // Utilized by StopLimitonQuote
        double stop;
        double limit;
    };
};


enum class ActionType : uint8_t {
    Buy,
    Sell,
    BuyOnCover,
    COUNT // yields # if elements in enum, useful for ranges :)
};


enum class PriceType : uint8_t {
    Market,
    MarketOnClose,
    Limit,
    StopOnQuote,
    StopLimitOnQuote,
    TrailingStopDollar,
    TrailingStopPercent,
    COUNT                   // yields # if elements in enum, useful for ranges :)
};


// Helper Functions 
std::string to_string(PriceType pt);
std::string to_string(ActionType at);
void to_string(PriceType pt, PriceValue pv);





