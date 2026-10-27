import pandas as pd

data = pd.read_csv("data/processed/NESO_price_data_24.10.26_13:00[PROCESSED].csv")

split_ratio = 0.8

trainingData = data[:int(len(data)*split_ratio)]
testingData = data[int(len(data)*split_ratio):]

trainingData.to_csv("data/processed/NESO_price_data_24.10.26_13:00[TRAINING].csv",index=False)
testingData.to_csv("data/processed/NESO_price_data_24.10.26_13:00[TESTING].csv",index=False)