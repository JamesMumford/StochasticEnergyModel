#pragma once
#include <functional>
#include "Distribution.hpp"

using BiVariateFunction = std::function<double(double,double)>;

class StochasticProcess
{
    public:
        StochasticProcess(BiVariateFunction driftFunction, BiVariateFunction diffusionFunction,Distribution& jumpWaitingDistribution,Distribution& jumpSizeDistribution);
        double getDrift(double t, double x_t);
        double getDiffusion(double t, double x_t);
    private:
        BiVariateFunction driftFunction_;
        BiVariateFunction diffusionFunction_;
        Distribution& jumpWaitingDistribution_;
        Distribution& jumpSizeDistribution_;
};