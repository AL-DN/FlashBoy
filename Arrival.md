# Arrival Class

**- double peak_lambda**
Allows specification for greatest lambda that will be passed to poisson dist (passed to lambda function as Amplitutde)

**- double wavelength**
Amount of hours in between peaks
    - We want one on morning open(9:30am), 1:00pm, and just tbefore market close (430pm) -> 3 hour delta

**- std::poisson_distribution\<double> arrival_dist**

## Functions

**- double get_norm_time(std::chrono::time_point\<std::chrono::system_clock> raw_time)**
    Returns normalized hours from market open range from 0 (start of trading day 9:30am) -> 7.5(end of trading day 5pm), so it can properly fit in cosine based function. **Invalid time of day, should be validated before an arrival time or price is generated**
$$
norm\_time(raw\_time) =
\begin{cases}
rawtime  \% 9.5 ) & \text{if } raw\_time \ge 9:30 & \le5:30 \\
throw std::invalid\_arguement & \text{otherwise}
\end{cases}
$$

**- double get_lambda(norm_time)**
```
lambda(norm_time) = peak_lambda * cos((2π / wavelength) * norm_time) + peak_lambda
```

**- get_network_latency()**
    
    1. double norm_time = get_norm_time(raw_time)
    2. double lambda = get_lambda(norm_time)
    3. Set poisson lambda = lambda
    4. return sample from poisson
    
    
