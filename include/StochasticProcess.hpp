#pragma once
#include <functional>
#include "Distribution.hpp"

using BiVariateFunction = std::function<double(double,double)>;

class StochasticProcess
{
    public:
        StochasticProcess(BiVariateFunction driftFunction, BiVariateFunction diffusionFunction, Distribution& jumpWaitingDistribution, Distribution& jumpSizeDistribution)
        : driftFunction_(driftFunction), diffusionFunction_(diffusionFunction), jumpWaitingDistribution_(jumpWaitingDistribution), jumpSizeDistribution_(jumpSizeDistribution){};
    private:
        BiVariateFunction driftFunction_;
        BiVariateFunction diffusionFunction_;
        Distribution& jumpWaitingDistribution_;
        Distribution& jumpSizeDistribution_;
};