import pandas as pd
import numpy as np
import math

meanFiles = ["data/numericalAnalysis/Weekday" + str(i) + "HourlyAverages" for i in range(7)]
fullTrainingData = "data/processed/NESO_price_data_24.10.26_13:00[TRAINING].csv"

meansData = []
for i in range(7):
    meansData.append(pd.read_csv(meanFiles[i]))

data = pd.read_csv(fullTrainingData)
data["Date"] = pd.to_datetime(data["Date"])
data["Estimated Mean"] = data.apply(
    lambda row: meansData[row["Date"].day_of_week].iloc[int(row["Timestamp"][:2]),0],
    axis=1
)
data["Residual"] = data["Price"] - data["Estimated Mean"]

# We assume Ornstein Uhlenbeck process with mean 0,
# and sum with a deterministic component "Estimated Mean" 
# which is the mean across the year of price
# on that weekday at that hour.
# Since we have hourly data, will use delta t = 1/24.
# The residuals between deterministic and truew price
# should then have the SDE:
# X_t = -k * X_t * dt + sigma * dW_t
# where W_t is standard BM, k is reversion constant, X_t is residual for time t,
# and sigma is volatility coefficient of diffusion element
# Over delta t increment,
# X_{t+delta t} = e^(-k * delta t) * X_t + N(0,sigma^2 * delta t)
# We notice the normal variable has mean 0 so we can estimate k
# by performing least squares regression on the linear model
# X_{t + delta t} = cX_t + error
# to find c, and then compute k.

residuals = data["Residual"].dropna().to_numpy()
delta_t = 1/24
x_t_add_delta = residuals[1:]
x_t = residuals[:-1]
c = np.dot(x_t_add_delta,x_t) / np.dot(x_t,x_t)
k = -math.log(c) / delta_t

# we then compute errors from the linear model and true prices,
# and compute the value of sigma implied by these errors' variance
errors = x_t_add_delta - c * x_t
errorVariance = np.dot(errors,errors) / (np.size(residuals) - 1)
sigma = math.sqrt(errorVariance * 2 * k / (1 - math.exp(-2 * k * delta_t)))

#print("Reversion constant k: " + str(k))
#print("Diffusion stdev sigma: " + str(sigma))

# program yields k = 1.0876255477170487
# program yields sigma = 124.93650246272517



