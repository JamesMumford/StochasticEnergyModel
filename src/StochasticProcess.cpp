#include "StochasticProcess.hpp"
#include <iostream>

StochasticProcess::StochasticProcess(BivariateFunction driftFunction, BivariateFunction diffusionFunction, Distribution& jumpWaitingDistribution, Distribution& jumpSizeDistribution)
: driftFunction_(driftFunction), diffusionFunction_(diffusionFunction), jumpWaitingDistribution_(jumpWaitingDistribution), jumpSizeDistribution_(jumpSizeDistribution), nextJumpTime_(0){};


double StochasticProcess::getDrift(double t, double x_t)
{
    return driftFunction_(t, x_t);
}

double StochasticProcess::getDiffusion(double t, double x_t)
{
    return diffusionFunction_(t, x_t);
}

double StochasticProcess::getJump(double t_prev, double t_new, std::mt19937& generator)
{
    double jumpSize = 0;
    while (t_new > nextJumpTime_)
    {
        double sampleIncrease = jumpWaitingDistribution_.sample(generator);
        nextJumpTime_ += sampleIncrease;
        jumpSize += jumpSizeDistribution_.sample(generator);
    }
    return jumpSize;
}

void StochasticProcess::setJumpWait(std::mt19937& generator)
{
    nextJumpTime_ = jumpWaitingDistribution_.sample(generator);
}

double StochasticProcess::getNextJumpTime()
{
    return nextJumpTime_;
}

std::function<double(double,double)> StochasticProcess::getDriftFunction()
{
    return driftFunction_;
}

std::function<double(double,double)> StochasticProcess::getDiffusionFunction()
{
    return diffusionFunction_;
}

