// Author: Alden Sahi
// Date: 07/17/2026
// Program Name: MarketTypeHelpers.cpp
// Program Description:
/*  
    C++ does not have a built-in way to convert enum values to strings s.t they can be printed in console. 
    This file provides helper functions to convert the ActionType and PriceType enums to their string representations.
*/


#include <string>

#include "MarketTypes.h"


// Overload to_string to work for ActionType and PriceType enums
std::string to_string(PriceType price_type) {
    // Converts PriceType to a string (can only print fundamental types to console)
    switch (price_type) {
        case PriceType::Market:              return "Market";
        case PriceType::MarketOnClose:       return "MarketOnClose";
        case PriceType::Limit:               return "Limit";
        case PriceType::StopOnQuote:         return "StopOnQuote";
        case PriceType::StopLimitOnQuote:    return "StopLimitOnQuote";
        case PriceType::TrailingStopDollar:  return "TrailingStopDollar";
        case PriceType::TrailingStopPercent: return "TrailingStopPercent";
    }
    return "unknown";
}
std::string to_string(ActionType action_type) {
    switch (action_type) {
        case ActionType::Buy:                return "Buy";
        case ActionType::Sell:               return "Sell";
        case ActionType::BuyOnCover:         return "BuyOnCover";
    }
    return "unknown";
}