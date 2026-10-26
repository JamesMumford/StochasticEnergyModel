import matplotlib.pyplot as plt
import pandas as pd
from statsmodels.tsa.stattools import acf

filepath = "data/processed/NESO_price_data_24.10.26_13:00[PROCESSED].csv"

# time of day analsis yielded these mean prices for each hour 00:00, 01:00, etc
hourly_means = [99.69479312197744,95.87430413756044,91.18840408382592,90.47703922622246,95.22422890918861,110.04663621708758,123.2779957012359,126.70675980655561,124.72581407845246,118.19993551853841,111.84484148307362,107.50365932294466,104.36670069854917,103.28008060182697,106.37960236432026,118.61871574422354,142.64195056421278,164.3443471252015,159.04448683503495,144.16853842020421,129.87918323482,116.49133799032778,109.15211600429645,102.55490059108007]
# day of week analysis yielded these mean prices for each day Monday, Tuesday, etc

def plot_autocorrelation(filepath):
    data = pd.read_csv(filepath)
    time_series = data["Price"]
    autocorrelations = acf(time_series,nlags=75,fft=False)

    plt.figure(figsize=(20,10))
    plt.scatter(range(len(autocorrelations)),autocorrelations)
    plt.xlabel("lag (timesteps)")
    plt.ylabel("autocorrelation")
    plt.title("NESO energy price time series autocorrelation")
    plt.grid(alpha=0.5)
    plt.savefig("data/processed/NESOautocorrelationUpTo75")

def plot_time_adjusted_autocorrelations(filepath):
    data = pd.read_csv(filepath)
    data["TimeAdjustedPrice"] = data.apply(
        lambda row: row["Price"] - hourly_means[int(row["Timestamp"][0:2])],
        axis=1
    )
    autocorrelations = acf(data["TimeAdjustedPrice"],nlags=3000,fft=False)
    print("running")
    plt.figure(figsize=(20,10))
    plt.scatter(range(len(autocorrelations)),autocorrelations)
    plt.xlabel("lag (timesteps)")
    plt.ylabel("autocorrelation of time-adjusted prices")
    plt.title("NESO energy price time series autocorrelation, adjusted for time of day")
    plt.grid(alpha=0.5)
    plt.savefig("data/processed/NESOtimeAdjustedAutocorrelationUpTo3000")

plot_time_adjusted_autocorrelations(filepath)