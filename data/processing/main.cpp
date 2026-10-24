#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>

const std::string dataFile = "NESO_price_data_24.10.26_13:00";

int main()
{
    std::ifstream input("data/unprocessed/"+dataFile+".csv");
    std::ofstream output("data/processed/"+dataFile + "[PROCESSED].csv");

    if ((!input.is_open()) || (!output.is_open()))
    {
        std::cerr << "Error opening files!";
    }

    std::string line;
    std::getline(input,line);

    output << "Date,Timestamp,Price\n";

    int rowsRead = 0;
    int rowsWritten = 0;
    int invalidRows = 0;

    while (std::getline(input, line))
    {
        rowsRead++;
        std::stringstream lineStream(line);
        std::string date;
        std::string timestamp;
        std::string price;
        std::string end;

        if ((std::getline(lineStream,date,',')) && (std::getline(lineStream,timestamp,',') && (std::getline(lineStream,price,','))))
        {
            std::stringstream timeStream(timestamp);
            std::string time;
            std::getline(timeStream,time,'-');
            double priceNumeric = std::stod(price);

            if ((!std::isfinite(priceNumeric)) || date.empty() || timestamp.empty())
            {
                invalidRows++;
            }
            else
            {
                output << date << ',' << time.substr(0,5) << ',' << price << '\n';
                rowsWritten++;
            }
        }
        else
        {
            invalidRows++;
        }
    }
    std::cout << "Rows read: " << rowsRead;
    std::cout << "\nRows written: " << rowsWritten;
    std::cout << "\nInvalid rows: " << invalidRows << '\n';
}