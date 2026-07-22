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
#include <cmath>
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
    throw std::invalid_argument("[to_string] PriceType Defined but Unhandled Print Logic");
}


std::string to_string(ActionType at) {
    // Converts PriceType to a string (can only print fundamental types to console)
    switch (at) {
        case ActionType::Buy:                return "Buy";
        case ActionType::Sell:               return "Sell";
        case ActionType::BuyOnCover:         return "BuyOnCover";
    }
    throw std::invalid_argument("[to_string] ActionType Defined but Unhandled Print Logic");
}


std::string to_string(PriceType pt, PriceValue pv) {
    // Converts PriceType to a string (can only print fundamental types to console)
    /* PSUEDOCODE
    if market/marketonclose we dont have values
    else if not stoplimitonquote
        print threshold
    else if stoplimitonquote
        print stop and limit
    else 
        throw error
    */

    if (pt == PriceType::Market || pt == PriceType::MarketOnClose) {
        return "PriceType::Market/MarketOnClose do not need PriceValue defined.";
    }
    else if ( pt == PriceType::Limit || pt == PriceType::StopOnQuote ||
             pt == PriceType::TrailingStopDollar || pt == PriceType::TrailingStopPercent ) {
       return "Threshold: " + std::to_string(pv.threshold); 
    } 

    else if ( pt == PriceType::StopLimitOnQuote ) {
        return "Stop Price: " + std::to_string(pv.stop) + ", Limit: " + std::to_string(pv.limit) + "."; 
    }

    else {
        throw std::invalid_argument("[to_string] Unhandled PriceType, cannot print PriceValue for: " + to_string(pt));
    }
}

void validate_price_value(PriceType pt, PriceValue pv) {
    switch (pt) {
        case PriceType::Market:
        case PriceType::MarketOnClose:
            return;

        case PriceType::Limit:
        case PriceType::StopOnQuote:
        case PriceType::TrailingStopDollar:
        case PriceType::TrailingStopPercent:
            if (!std::isfinite(pv.threshold) || pv.threshold <= 0.0f) {
                throw std::invalid_argument(
                    "PriceValue.threshold must be a positive finite value for PriceType::" + to_string(pt));
            }
            return; // allows correct values to return 

        case PriceType::StopLimitOnQuote:
            if (!std::isfinite(pv.stop) || pv.stop <= 0.0f ||
                !std::isfinite(pv.limit) || pv.limit <= 0.0f) {
                throw std::invalid_argument(
                    "PriceValue.stop/limit must be positive finite values for PriceType::StopLimitOnQuote");
            }
            return; // allows correct values to return 

        case PriceType::COUNT:
            break;  // falls through to the throw below
    }

    throw std::invalid_argument("Unhandled PriceType (raw value: " + std::to_string(static_cast<int>(pt)) + ")");
}
