## Order Class

**- std::string symbol** 

**- enum action** 
    Description: (buy, buy to cover, sell)

**- uint16_t quantity**
    - Always >=1 and fixed bit size ( can scale based on requirments like purchasing power with profile data. Q: How much do we need to store vs how much do we get back in speed? )

**- enum price_type** -> (market, market on close, limit, stop on quote, stop limit on quote, trailing stop $, trailing stop %)
- double price 
    avail:
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
