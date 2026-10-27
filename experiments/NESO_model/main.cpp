#include "OrnsteinUhlenbeck.hpp"
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

double getDeterministicComponent(int day, int hour);

int main()
{
    /* residual model fitted with parameters inferred from NESO data */
    OrnsteinUhlenbeck residualModel(1.0876255477170487,0,124.93650246272517);

    std::cout << getDeterministicComponent(0,5);
}

double getDeterministicComponent(int day, int hour)
{
    std::ifstream input = std::ifstream("data/numericalAnalysis/Weekday" + std::to_string(day) + "HourlyAverages.csv");
    if (!input.is_open())
    {
        std::cout << "Error: file not found";
        return 0;
    }
    std::string line;
    for (int i = 0; i < hour + 2; i++)
    {
        std::getline(input,line);
    }
    return std::stod(line);







}