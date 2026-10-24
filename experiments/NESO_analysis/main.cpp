#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

std::vector<long double> GetMeanAndVariance(std::string dataFile);

const std::string dataFile = "data/processed/NESO_price_data_24.10.26_13:00[PROCESSED].csv";

int main()
{
    std::vector<long double> dataProperties = GetMeanAndVariance(dataFile);

    std::cout << "NESO Pricing Data Summary:\n" << "Mean: " << dataProperties[0] << "\nVariance: " << dataProperties[1] << "\n";

}

std::vector<long double> GetMeanAndVariance(std::string dataFile)
{
    std::ifstream input(dataFile);

    if (!input.is_open())
    {
        std::cerr << "Failed to open file!";
        return std::vector<long double>{0,0};
    }

    std::string line;
    std::getline(input,line);

    long double mean = 0;
    long double sumOfSquares = 0;
    long double variance = 0;
    int valueCount = 0;

    while (std::getline(input,line))
    {
        long double value;
        std::stringstream lineStream(line);
        std::string valueString;
        std::getline(lineStream,valueString,',');
        std::getline(lineStream,valueString,',');
        std::getline(lineStream,valueString,',');
        try
        {
            value = std::stod(valueString);
            mean += value;
            sumOfSquares += value * value;
            valueCount++;
        }
        catch(const std::invalid_argument& e)
        {
            std::cout << "INVALID ARGUMENT - CHECK IF .CSV IS CLEANED" << '\n';
        }
        
    }
    mean /= valueCount;
    variance = (sumOfSquares / valueCount) - mean * mean;
    return std::vector<long double>{mean,variance};
}

