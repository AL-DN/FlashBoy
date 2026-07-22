// Author: Alden Sahi
// Date: 07.17.2026
// Program Name: MarketTypeHelpers.cpp
// Program Description:
/*  
    C++ does not have a built-in way to convert enum class values to strings s.t they can be printed in console. 
    This file provides helper functions to convert the ActionType and PriceType enums to their string representations.
*/

#include <string>
#include <iostream>
#include "MarketTypes.h"

std::string to_string(PriceType pt) {
    // Converts PriceType to a string (can only print fundamental types to console)
    switch (pt) {
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


std::string to_string(ActionType at) {
    // Converts PriceType to a string (can only print fundamental types to console)
    switch (at) {
        case ActionType::Buy:                return "Buy";
        case ActionType::Sell:               return "Sell";
        case ActionType::BuyOnCover:         return "BuyOnCover";
    }
    return "unknown";
}


void to_string(PriceType pt, PriceValue pv) {
    // Converts PriceType to a string (can only print fundamental types to console)
    /* PSUEDOCODE
    
    if not stoplimitonquote
        print threshold
    else
        print stop and limit
    
    */
    if (pt != PriceType::StopLimitOnQuote) {
        std::cout << "Threshold: " << pv.threshold << "\n"; 
    } 
    else {
        std::cout << "Stop Price: " << pv.stop << "\n"; 
        std::cout << "Limit: " << pv.limit << "\n"; 
    }
}