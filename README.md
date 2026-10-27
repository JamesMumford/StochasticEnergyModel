# Lévy Process Modelling of Energy Pricing Dynamics
This is a C++ Monte Carlo pricing implementation I have made in an attempt to understand the dynamics affecting energy pricing. Like many other commodities, 
energy prices are generally mean reverting due to higher prices driving down demand and vice versa, and are usually modelled with an additional layer of 
continuous noise. However, there is a high cost to sitting on an energy reserve (stored energy depletes, and buying / maintaining / leasing energy storage is expensive) which means 
moderate mismatches in supply and demand can cause large fluctuations in price.
Suppliers sometimes continue to produce and sell electricity into the grid while operating at a loss due to the cost of shutting down and restarting generators, in the hope that 
energy prices will return to a profitable level in a short enough time horizon. However, this can potentially further depress prices and even lead to negative prices.

To start with, I have implemented a couple of common stochastic differential equation models - geometric Brownian motion and the Ornstein-Uhlenbeck process.
The goal is eventually to consider several possible pricing models, use historical spot price data to infer what the model parameters should be, and then
test each of the models out of sample with those parameters to see if it behaves well. This could then be used, for example, in a Monte Carlo estimate 
for pricing an option on the underlying.

The first experiment with real data uses the NESO's Day Ahead Power Exchanges Prices (Nord Pool) dataset which is freely available (https://www.neso.energy/data-portal/day-ahead-power-exchange-prices-nordpool). I first wanted to see how the energy price process was correlated with itself at different time offsets to identify any daily / weekly patterns, so used pandas and matplotlib to construct the below graphs of autocorrelation on energy prices. Note that the dataset gives prices once per hour, so each timestep is one hour.

<img width="2000" height="1000" alt="NESOautocorrelationUpTo25" src="https://github.com/user-attachments/assets/4512d387-cc77-435f-b642-b58d63aa9585" />
<img width="2000" height="1000" alt="NESOautocorrelationUpTo300" src="https://github.com/user-attachments/assets/b8d20d4f-738b-421a-8be0-41d7d64939e8" />
<img width="2000" height="1000" alt="NESOautocorrelationUpTo75" src="https://github.com/user-attachments/assets/2209f4fc-413c-46c0-965f-8f5bfbfeda1c" />

We notice straight away there is a peak at multiples of 24 hours, indicating that the specific hour of the day may have some useful predictive power over the price of energy. So as a first basic model, I ran some more python analysis to compute average energy price for each hour of the day, on each weekday. I did consider just doing it for each hour of the day in aggregate, but noticed that the power price patterns for different days of the week was quite different. See an example of this disparity below:

<img width="2000" height="1000" alt="NESOmeanPriceByTimeSunday" src="https://github.com/user-attachments/assets/b8b5ac22-16a1-4434-9ccc-6375f3670094" />

<img width="2000" height="1000" alt="NESOmeanPriceByTimeThursday" src="https://github.com/user-attachments/assets/41469369-54bd-4673-a67f-7ac9202eafe1" />


## Current Features
- Brownian motion, geometric Brownian motion and Ornstein-Uhlenbeck process simulation
- Pure jump process simulation
    - Jump intensity is modelled as a function of time and current state (for example, higher prices may lead to an increased chance of jumps occurring in a given time interval)
- Euler-Maruyama time-stepping scheme used to discretise the SDEs for a numerical solution
    - Modular design allows later use of different numerical schemes

## Soon To Be Released Features
- General Lévy process simulation (processes which consist of an SDE summed with a pure jump component)
    - Jump size distribution modelled as a function of current state and time (for example, low prices may be more likely to experience positive shocks, while high prices
      might be more likely to experience negative ones)
    - Mean reversion of continuous component and mean reversion of jump component to be modelled separately (jumps often experience very sharp mean reversion, so it may be
      beneficial if they are not subject to the same reversion rate as continuous deviations from the baseline)
- Introduce some independent market variables (seasonality, weather conditions, economic conditions etc) which also affect the process' drift, diffusion, jump intensity and
  jump size distribution

