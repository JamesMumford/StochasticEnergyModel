import pandas as pd
import matplotlib.pyplot as plt
from timeOfDayAnalysis import plot_mean_price_by_time

filename = "data/processed/NESO_price_data_24.10.26_13:00[PROCESSED].csv"

def plot_mean_price_by_weekday(filename):
    data["Date"] = pd.to_datetime(data["Date"])
    data["Weekday"] = data["Date"].dt.day_of_week
    weekday_means = [0 for i in range(7)]
    weekday_individualised_series = [0 for i in range(7)]

    for i in range(7):
        weekday_individualised_series[i] = data[data["Weekday"] == i]
        weekday_means[i] = weekday_individualised_series[i]["Price"].mean()

    plt.figure(figsize=(20,10))
    plt.scatter(["Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"],weekday_means)
    plt.title("NESO mean energy price by weekday")
    plt.xlabel("Weekday")
    plt.ylabel("Price (£/MWhr)")
    plt.grid(alpha=0.5)
    plt.savefig("data/processed/NESOmeanPriceByWeekday")

def plot_hourly_prices_by_weekday(data):
    weekday_specific_series = []
    data["Date"] = pd.to_datetime(data["Date"])
    data["Weekday"] = data["Date"].dt.day_of_week
    for i in range(7):
        weekday_specific_series.append(data[data["Weekday"] == i])
        weekday_specific_hourly_averages = []
        for j in range(24):
            weekday_specific_hourly_averages.append(weekday_specific_series[i][weekday_specific_series[i]["Timestamp"] == str(j).zfill(2) + ":00"]["Price"].mean())

        plt.figure(figsize=(20,10))
        plt.scatter( [str(i).zfill(2) + ":00" for i in range(24)], weekday_specific_hourly_averages)
        plt.xlabel("Time of day")
        day = ["Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"][i]
        plt.ylabel("Mean price (£/MWhr) on a" + day)
        plt.title("NESO mean energy price by time of day, on a " + day)
        plt.grid(alpha=0.5)
        plt.savefig("data/processed/NESOmeanPriceByTime" + day + ".png")


data = pd.read_csv(filename)
plot_hourly_prices_by_weekday(data)
