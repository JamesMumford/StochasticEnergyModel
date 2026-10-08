#include "StochasticProcess.hpp"

StochasticProcess::StochasticProcess(BiVariateFunction driftFunction, BiVariateFunction diffusionFunction, Distribution& jumpWaitingDistribution, Distribution& jumpSizeDistribution)
: driftFunction_(driftFunction), diffusionFunction_(diffusionFunction), jumpWaitingDistribution_(jumpWaitingDistribution), jumpSizeDistribution_(jumpSizeDistribution){};

double StochasticProcess::getDrift(double t, double x_t)
{
    return driftFunction_(t,x_t);
}

double StochasticProcess::getDiffusion(double t, double x_t)
{
    return diffusionFunction_(t, x_t);
}

