## Order Class

**- std::string symbol** 

**- enum action** 
    Description: (buy, buy to cover, sell)

**- uint16_t quantity**
    - Always >=1 and fixed bit size ( can scale based on requirments like purchasing power with profile data. Q: How much do we need to store vs how much do we get back in speed? )

**- enum price_type** -> (market, market on close, limit, stop on quote, stop limit on quote, trailing stop $, trailing stop %)
    Select Market to buy or sell a security at the prevailing market price when the order is eligible for execution.

    Select Market on close to buy or sell a security as a market order as close as possible to the close of regular session trading for that security.

    Select Limit to buy a security at (or below) a specific price, or to sell a security at (or above) a specific price.

    Select Stop on quote to buy or sell a security when its market price (ask price for buy orders and bid price for sell orders) reaches a specified stop price, upon which the order will turn into a market order.

    Select Stop limit on quote to buy or sell a security when its market price (ask price for buy orders and bid price for sell orders) reaches a specified stop price, upon which the order will turn into a limit order.

    Select Trailing stop $ to buy or sell a security when its market price reaches a trailing stop price. The trailing stop price is initially specified in terms of points (stop value $) above (for buy orders) or below (for sell orders) a security's market price. The trailing stop price is automatically adjusted as the market fluctuates.

    Select Trailing stop % to buy or sell a security when its market price reaches a trailing stop price. The trailing stop price is initially specified in terms of percentage (stop value %) above (for buy orders) or below (for sell orders) a security's market price. The trailing stop price is automatically adjusted as the market fluctuates.

**- double price**
    - market, market on close -> None
    - stop on quote -> stop price
    - limit -> limit price
    - stop limit on quote -> stop + limit price
    - trailing stop $ -> $
    - training stop % -> %

**-std::chrono::time_point init_time**
 Cannot modify. Datatype has high precision and same (8-byte worst case memory constrain as ctime).
 Root Node to create the expiration and arrival time class attributes ( most importantly best to initalize in contruction.)


**- bool is_active** 
This signifies the trade is still not filled nor cancelled. 


What is the expected functionality. That `OrderFlowGenerator` class is able to create these data types in order to simulate market. Using Poisson For arrivals and Geometric Brownian Motion for Price.

With these markets we cna generate random orders we can also slip in our own using different networking 