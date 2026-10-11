#include "OrnsteinUhlenbeck.hpp"
#include "EulerMaruyama.hpp"
#include "GeometricBrownianMotion.hpp"
#include <iostream>

#include "StandardDistributions.hpp"

const int noSteps = 50;
const int randomSeed = 77;
const double resolution = 0.0001;
const int noSims = 1000000;

int main()
{
    /*initialising sde processes*/
    OrnsteinUhlenbeck OUprocess(50,10,5);

    StochasticProcess& OUref = OUprocess;

    /*initialising process solvers*/
    EulerMaruyama OUsolver(OUref,resolution,randomSeed);

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

    return 0;

};