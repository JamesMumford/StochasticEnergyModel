#include "EulerMaruyama.hpp"
#include "OrnsteinUhlenbeck.hpp"
#include <iostream>
#include "StandardDistributions.hpp"
#include "UtilityFunctions.hpp"
#include <string>
#include <fstream>

/* Simulation parameters */
const unsigned int noSteps = 1000;
const int randomSeed = 77;
const double resolution = 0.01;
const int noSims = 1000;

/* Ornstein Uhlenbeck process parameters */
const double THETA = 10.0;
const double MU = 25.0;
const double SIGMA = 10.0;
const double T_0 = 0.0;
const double X_T_0 = 100;

double predictOUEV(StochasticProcess&);

int main()
{
    OrnsteinUhlenbeck OUprocess(THETA,MU,SIGMA);
    StochasticProcess& OUref = OUprocess;

    Utility::writeEulerMaruyamaSim(OUref,T_0,X_T_0,resolution,noSteps,noSims,randomSeed);
}

void comparePredictedToAnalyticOUEV(StochasticProcess& OUref)
{
    std::string filename;
    std::cout << "\nRead data from file: ";
    std::cin >> filename;

    std::ifstream file("results/ou/"+filename+".csv");

    if (!file.is_open())
    {
        std::cout << "Failed to open file!";
        return;
    }

    std::string line;

    for (int i = 0; i < 6; i++)
    {
        std::getline(file,line);
    }
}

double predictOUEV(StochasticProcess& OUref)
{
    std::vector<double> terminalValues(noSims);

    for (int i = 0; i < noSims; i++)
    {
        EulerMaruyama OUsolver(OUref,resolution,randomSeed + i);
        terminalValues[i] = OUsolver.simulatePath(T_0,X_T_0,noSteps);
    }

    double sum = 0;
    for (double num : terminalValues)
    {
        sum += num;
    }

    return sum / noSims;
}