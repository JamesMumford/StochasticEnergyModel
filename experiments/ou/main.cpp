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

double predictOUEV(OrnsteinUhlenbeck&);
void comparePredictedToAnalyticOUEV(OrnsteinUhlenbeck&);


int main()
{
    OrnsteinUhlenbeck OUprocess(THETA,MU,SIGMA);
    OrnsteinUhlenbeck& OUref = OUprocess;

    comparePredictedToAnalyticOUEV(OUref);

    /* Utility::writeEulerMaruyamaSim(OUref,T_0,X_T_0,resolution,noSteps,noSims,randomSeed);*/
}

void comparePredictedToAnalyticOUEV(OrnsteinUhlenbeck& OUref)
{
    double estimatedEV = predictOUEV(OUref);
    double trueEV = OUref.AnalyticEV(noSteps,X_T_0,resolution);
    double percentageError = 100 * fabs(trueEV - estimatedEV) / (double)(trueEV);

    std::cout << " Ornstein Uhlenbeck process\n Analytic EV: " << trueEV << "\n Estimated EV: " << estimatedEV;
    std::cout << "\n Error: " << std::to_string(percentageError) << "%\n";
    std::cout << "\n With parameters theta = " << THETA << "\n                 mu = " << MU << "\n                 sigma = " << SIGMA << "\n";
    std::cout << "                 paths = " << noSims << "\n                 timesteps = " << noSteps << "\n";
}

double predictOUEV(OrnsteinUhlenbeck& OUref)
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