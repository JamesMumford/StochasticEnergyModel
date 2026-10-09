#pragma once
#include <functional>
#include "Distribution.hpp"
#include <vector>

using BiVariateFunction = std::function<double(double,double)>;

class StochasticProcess
{
    public:
        StochasticProcess(BiVariateFunction driftFunction, BiVariateFunction diffusionFunction,Distribution& jumpWaitingDistribution,Distribution& jumpSizeDistribution);
        double getDrift(double t, double x_t);
        double getDiffusion(double t, double x_t);
        double getJump(double t_prev, double t_new, std::mt19937& generator);
        void setJumpWait(std::mt19937& generator);
    private:
        BiVariateFunction driftFunction_;
        BiVariateFunction diffusionFunction_;
        Distribution& jumpWaitingDistribution_;
        Distribution& jumpSizeDistribution_;
        double nextJumpTime;
};