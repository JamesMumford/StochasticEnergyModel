#include "EulerMaruyama.hpp"
#include "OrnsteinUhlenbeck.hpp"
#include <iostream>
#include "StandardDistributions.hpp"
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

    std::string filename;
    std::cout << "\nStore results in file: ";
    std::cin >> filename;

    std::ofstream file("results/ou/"+filename + ".csv");

    file << "THETA = " + std::to_string(THETA) + ", MU = " + std::to_string(MU) + ", SIGMA = " + std::to_string(SIGMA) + ", T_0 = " + std::to_string(T_0) + ", X_T_0 = " + std::to_string(X_T_0) + ", DELTA T = " + std::to_string(resolution) + "\n";
    file << "RANDOM SEEDS: " + std::to_string(randomSeed) + " + i\n";
    file << "NUMBER OF SIMS = " + std::to_string(noSims) + ", NUMBER OF STEPS PER SIM = " + std::to_string(noSteps) + "\n";

    std::vector<double> results;
    for (int i = 0; i < noSims; i++)
    {
        EulerMaruyama OUsolver(OUref, resolution, randomSeed + i);
        results = OUsolver.simulatePathHistory(T_0,X_T_0,noSteps);
        for (double val : results)
        {
            file << std::to_string(val) + ",";
        }
        file << "\n";
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