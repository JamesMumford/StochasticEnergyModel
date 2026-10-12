#include "StochasticProcess.hpp"
#include <iostream>

StochasticProcess::StochasticProcess(BivariateFunction driftFunction, BivariateFunction diffusionFunction, BivariateFunction jumpIntensity, std::unique_ptr<Distribution> jumpSizeDistribution)
: driftFunction_(driftFunction), diffusionFunction_(diffusionFunction), jumpIntensity_(jumpIntensity), jumpSizeDistribution_(std::move(jumpSizeDistribution)){};


double StochasticProcess::getDrift(double t, double x_t)
{
    return driftFunction_(t, x_t);
}

double StochasticProcess::getDiffusion(double t, double x_t)
{
    return diffusionFunction_(t, x_t);
}

double StochasticProcess::getJump(double t_prev, double t_new, double x_t_prev, std::mt19937& generator)
{
    double jumpSum = 0.0;
    double poissonCoefficient = (t_new - t_prev) * jumpIntensity_(t_prev, x_t_prev);
    jumpCountDistribution_.param(std::poisson_distribution<int>::param_type(poissonCoefficient));
    int jumpCount = jumpCountDistribution_(generator);

    for (int i = 0; i < jumpCount; i++)
    {
        jumpSum += (*jumpSizeDistribution_).sample(generator);
    }
    return jumpSum;
}

std::function<double(double,double)> StochasticProcess::getDriftFunction()
{
    return driftFunction_;
}

std::function<double(double,double)> StochasticProcess::getDiffusionFunction()
{
    return diffusionFunction_;
}

std::function<double(double,double)> StochasticProcess::getJumpIntensityFunction()
{
    return jumpIntensity_;
}

Distribution& StochasticProcess::getJumpSizeDistribution()
{
    return *jumpSizeDistribution_;
}

