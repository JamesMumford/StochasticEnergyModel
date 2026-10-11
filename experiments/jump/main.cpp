#include "EulerMaruyama.hpp"
#include "PureJumpProcess.hpp"
#include "StandardDistributions.hpp"
#include "Distribution.hpp"
#include <iostream>
#include <random>

double predictJumpEV(StochasticProcess&);

/* Simulation parameters*/
const int noSteps = 5;
const int randomSeed = 770;
const double resolution = 1;
const int noSims = 100;

/* Pure jump process parameters */
const double JUMP_TIME_INTENSITY = 4.0;
const double JUMP_SIZE_MU = 100;
const double JUMP_SIZE_SIGMA = 25;
const double X_0 = 0.0;

Exponential expObj(JUMP_TIME_INTENSITY);
Distribution& JUMP_TIME_DISTRIBUTION = expObj;
AbsoluteNormal normObj(JUMP_SIZE_MU, JUMP_SIZE_SIGMA);
Distribution& JUMP_SIZE_DISTRIBUTION = normObj;

int main()
{
    PureJumpProcess jumpProcess(JUMP_TIME_DISTRIBUTION, JUMP_SIZE_DISTRIBUTION);
    double jumpPrediction = predictJumpEV(jumpProcess);
    std::cout << "Jump model predicted value: " << jumpPrediction << std::endl;



}

double predictJumpEV(StochasticProcess& Jumpref)
{
    std::vector<double> terminalValues(noSims);

    for (int i = 0; i < noSims; i++)
    {
        EulerMaruyama JumpSolver(Jumpref,resolution,randomSeed + i);
        terminalValues[i] = JumpSolver.simulatePath(0,X_0,noSteps);
    }

    double sum = 0;
    for (double num : terminalValues)
    {
        sum += num;
    }

    return sum / noSims;
}