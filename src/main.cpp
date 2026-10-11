#include "OrnsteinUhlenbeck.hpp"
#include "EulerMaruyama.hpp"
#include "GeometricBrownianMotion.hpp"
#include <iostream>

#include "StandardDistributions.hpp"
#include <random>
#include <limits>

const int noSteps = 50;
const int randomSeed = 77;
const double resolution = 0.0001;
const int noSims = 1000000;

double predictGBMEV(StochasticProcess&);

int main()
{
    /*initialising sde processes*/
    OrnsteinUhlenbeck OUprocess(50,10,5);
    GeometricBrownianMotion GBMprocess(0,1);

    StochasticProcess& OUref = OUprocess;
    StochasticProcess& GBMref = GBMprocess;

    /*initialising process solvers*/
    EulerMaruyama OUsolver(OUref,resolution,randomSeed);
    EulerMaruyama GBMsolver(GBMref,resolution,randomSeed);

    /*path simulation*/
    /*vector<double> OUpathHistory = OUsolver.simulatePathHistory(0,5,no_steps);
    for (int i = 0; i < no_steps; i++)
    {
        std::cout << OUpathHistory.at(i) << "\n";
    }*/



    /*
    std::vector<double> GBMpathHistory = GBMsolver.simulatePathHistory(0,100,noSteps);
    for (int i = 0; i < noSteps; i++)
    {
        std::cout << GBMpathHistory.at(i) << "\n";
    }
    */

    double GBMEVprediction = predictGBMEV(GBMref);
    std::cout << "Estimated GBM terminal value: " << GBMEVprediction;

    return 0;

};
 
double predictGBMEV(StochasticProcess& GBMref)
{
    std::vector<double> terminalValues(noSims);

    for (int i = 0; i < noSims; i++)
    {
        EulerMaruyama GBMsolver(GBMref,resolution,randomSeed + i);
        terminalValues[i] = GBMsolver.simulatePath(0,100,noSteps);
    }

    double sum = 0;
    for (double num : terminalValues)
    {
        sum += num;
    }

    return sum / noSims;
}