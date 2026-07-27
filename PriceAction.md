# PriceAction Class

**- double S0** 
Initial Stock Price

**- double mu** 
Drift / Expected Annualized Return

**- double sigma**
Annualized Volatility

**- double T** 
Time Horizon in Years

**- double N**
Number of Time Steps

**- double dt**
Size of each time step


## Functions

**Constructor** 
Params:
    - S0, mu, sigma, T, N
Logic:
    Assignment, dt set to T/N

**next_timestep**
Calculates and Returns $S_{T+1}$



**sample_price**
samples price + V~N(0,sprea)


### Next Steps
ASYNC run_simualtion -> constant changes to S_0 w delay in loop

ASYNC
    - sample price
    - attach order time 
    - attach to priority queue
    - populate order book
    - match