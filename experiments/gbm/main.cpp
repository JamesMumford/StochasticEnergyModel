#include "EulerMaruyama.hpp"
#include "GeometricBrownianMotion.hpp"
#include <iostream>
#include "StandardDistributions.hpp"

/* Simulation parameters */
const int noSteps = 5000;
const int randomSeed = 77;
const double resolution = 0.001;
const int noSims = 1000;

/* Geometric Brownian motion process parameters */
const double MU = 5.6;
const double SIGMA = 1.0;
const double X_0 = 100;

double predictGBMEV(StochasticProcess&);

int main()
{
    GeometricBrownianMotion GBMprocess(MU,SIGMA);
    StochasticProcess& GBMref = GBMprocess;
    EulerMaruyama GBMsolver(GBMref,resolution,randomSeed);

    double GBMEVprediction = predictGBMEV(GBMref);
    std::cout << "Estimated GBM terminal value: " << GBMEVprediction;

}

double predictGBMEV(StochasticProcess& GBMref)
{
    std::vector<double> terminalValues(noSims);

    for (int i = 0; i < noSims; i++)
    {
        EulerMaruyama GBMsolver(GBMref,resolution,randomSeed + i);
        terminalValues[i] = GBMsolver.simulatePath(0,X_0,noSteps);
    }

    double sum = 0;
    for (double num : terminalValues)
    {
        sum += num;
    }

    return sum / noSims;
}