#include "OrnsteinUhlenbeck.hpp"
#include "EulerMaruyama.hpp"
#include "GeometricBrownianMotion.hpp"
#include <iostream>

#include "StandardDistributions.hpp"
#include <random>
#include <limits>

const int no_steps = 50;
const int randomSeed = 77;
const double resolution = 0.0001;

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

    
    std::vector<double> GBMpathHistory = GBMsolver.simulatePathHistory(0,100,no_steps);
    for (int i = 0; i < no_steps; i++)
    {
        std::cout << GBMpathHistory.at(i) << "\n";
    }

};