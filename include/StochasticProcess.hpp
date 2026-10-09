#pragma once
#include <functional>
#include "Distribution.hpp"
#include <vector>

using BivariateFunction = std::function<double(double,double)>;

class StochasticProcess
{
    public:
        StochasticProcess(BivariateFunction driftFunction, BivariateFunction diffusionFunction,Distribution& jumpWaitingDistribution,Distribution& jumpSizeDistribution);
        double getDrift(double t, double x_t);
        double getDiffusion(double t, double x_t);
        double getJump(double t_prev, double t_new, std::mt19937& generator);
        void setJumpWait(std::mt19937& generator);
        std::function<double(double,double)> getDriftFunction();
        std::function<double(double,double)> getDiffusionFunction();
    private:
        BivariateFunction driftFunction_;
        BivariateFunction diffusionFunction_;
        Distribution& jumpWaitingDistribution_;
        Distribution& jumpSizeDistribution_;
        double nextJumpTime;
};