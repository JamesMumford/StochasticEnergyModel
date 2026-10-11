#include "EulerMaruyama.hpp"
#include "OrnsteinUhlenbeck.hpp"
#include <iostream>

#include "StandardDistributions.hpp"
#include <random>
#include <limits>

/* Simulation parameters */
const int noSteps = 1000;
const int randomSeed = 77;
const double resolution = 0.01;
const int noSims = 1000;

/* Ornstein Uhlenbeck process parameters */
const double THETA = 10.0;
const double MU = 25.0;
const double SIGMA = 10.0;
const double X_0 = 100;

double predictOUEV(StochasticProcess&);

int main()
{
    OrnsteinUhlenbeck OUprocess(THETA,MU,SIGMA);
    StochasticProcess& OUref = OUprocess;

    double OUEVprediction = predictOUEV(OUref);
    std::cout << "Estimated OU terminal value: " << OUEVprediction;

}

double predictOUEV(StochasticProcess& OUref)
{
    std::vector<double> terminalValues(noSims);

    for (int i = 0; i < noSims; i++)
    {
        EulerMaruyama OUsolver(OUref,resolution,randomSeed + i);
        terminalValues[i] = OUsolver.simulatePath(0,X_0,noSteps);
    }

    double sum = 0;
    for (double num : terminalValues)
    {
        sum += num;
    }

    return sum / noSims;
}