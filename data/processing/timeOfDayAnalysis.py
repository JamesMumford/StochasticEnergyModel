import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv("data/processed/NESO_price_data_24.10.26_13:00[PROCESSED].csv")

time_individualised_series = []
time_individualised_means = [0 for i in range(24)]

for i in range(24):
    time_individualised_series.append(data[data["Timestamp"] == str(i).zfill(2) + ":00"]["Price"])
    time_individualised_means[i] = time_individualised_series[i].mean()

plt.figure(figsize=(20,10))
plt.scatter( [str(i).zfill(2) + ":00" for i in range(24)], time_individualised_means)
plt.xlabel("Time of day")
plt.ylabel("Mean price (£/MWhr)")
plt.title("NESO mean energy price by time of day")
plt.grid(alpha=0.5)
plt.savefig("data/processed/NESOmeanPriceByTime.png")

output = ""
for i in range(24):
    output += str(time_individualised_means[i]) + ","
print(output)






