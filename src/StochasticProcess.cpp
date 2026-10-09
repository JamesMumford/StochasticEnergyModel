#include "StochasticProcess.hpp"
#include <iostream>

StochasticProcess::StochasticProcess(BiVariateFunction driftFunction, BiVariateFunction diffusionFunction, Distribution& jumpWaitingDistribution, Distribution& jumpSizeDistribution)
: driftFunction_(driftFunction), diffusionFunction_(diffusionFunction), jumpWaitingDistribution_(jumpWaitingDistribution), jumpSizeDistribution_(jumpSizeDistribution), nextJumpTime(0){};

double StochasticProcess::getDrift(double t, double x_t)
{
    std::cerr << "Before drift call: t=" << t
              << ", x_t=" << x_t << '\n';

    double result = driftFunction_(t, x_t);

    std::cerr << "After drift call: result=" << result << '\n';

    return result;
}

double StochasticProcess::getDiffusion(double t, double x_t)
{
    return diffusionFunction_(t, x_t);
}

double StochasticProcess::getJump(double t_prev, double t_new, std::mt19937& generator)
{
    double jumpSize = 0;
    while (t_new > nextJumpTime)
    {
        std::cout << jumpWaitingDistribution_.sample(generator) << "\n";
        double sampleIncrease = jumpWaitingDistribution_.sample(generator);
        nextJumpTime += sampleIncrease;
        std::cout << nextJumpTime << "added: " << sampleIncrease << " \n";
        jumpSize += jumpSizeDistribution_.sample(generator);
    }
    return jumpSize;
}

void StochasticProcess::setJumpWait(std::mt19937& generator)
{
    nextJumpTime = jumpWaitingDistribution_.sample(generator);
}

