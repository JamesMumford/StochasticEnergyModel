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
- Brownian motion, geometric Brownian motion, Ornstein-Uhlenbeck process path simulation, including automatic recording of either full path histories or just path terminal values, to a csv file.
- Option class, which has functionality to generate a Monte Carlo estimate of the European call/put expected value on an underlying jump process or SDE, assuming a particular risk free rate of return in the market.
    - Includes functionality for finding a 100- $ \alpha $` confidence interval on the value of the European calls/puts.
- Arbitrary Lévy process path simulation
    - Extended supported stochastic processes to include non-Lévy processes which consist of an SDE component summed with a jump process component.
    - Jump processes have jump intensities which are themselves functions of time and the state of the process (for example, real electricity markets often observe shocks being followed by increased shock intensities shortly afterward, so this is a phenomenon we could now incorporate using this model).
    - Jump processes have dynamic jump size distributions, dependent on time and the state of the process.
- Solver class acts as interface for numerically simulating paths of stochastic processes.
    - All simulations currently use Euler-Maruyama child class (which implements the Euler-Maruyama method) as the method of path computation.
- Imported hourly NESO electricity spot price data (dates back to 20/9/2021).
    - Cleaned NESO time series data by making data_cleaning C++ executable.
    - Used pandas to divide NESO data into a testing and a training split.
    - Used pandas, NumPy to conduct autocorrelation analysis of NESO data, identifying daily and weekly trends in prices.
    - Constructed composite model consisting of deterministic component (a function of weekday and time of day) summed with an Ornstein-Uhlenbeck process, to try and find a good model to represent the NESO data.
    - Inferred what the Ornstein-Uhlenbeck parameters would be from the training split of the NESO data.

## Soon To Be Released Features
- Further NESO data analysis.
    - Examine the goodness of fit of our composite model (as described above) on the testing split of the NESO data.
    - Investigate longer term energy price trends (e.g. monthly, annual) and see if increased complexity of the deterministic component gives better results on test split.
    - Test if adding a pure jump process into our composite model gives better results on test split of NESO data.
    - Test if adding a multi-regime switching jump component to the composite model gives better results on test data.
    - Test if adding a jump component with a size distribution that induces mean reverting behaviour gives better results on test data.
    - Test if using a jump intensity which is a function of state (or jump history) gives better results on data, and find which basic function is best.
- Add in historical energy production forecast data from solar, wind, nuclear and gas, and historical energy deman forecasts.
    - Since the marginal cost of energy production is usually a significant driver of electricity prices, we want to find a way of determining which power production types in the merit-order ranking are likely to be used in a given hour, so we can base our spot price prediction on the most expensive marginal production cost of these production types.
    - For simplicity, we will likely just use NESO's own solar, wind, nuclear energy production forecasts, rather than developing our own methods to predict future production.
    - Using the forecasted energy demand, we can then predict which of the energy production types will likely be in use in a given hour, to compute the amrginal cost of energy production.
    - We can then implement a regime-switching model based on this marginal energy production cost to try and capture NESO energy spot prices more accurately.
    - We will test this model on the NESO energy spot prices test split, to determine if it adds any predictive value.

