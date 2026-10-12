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

