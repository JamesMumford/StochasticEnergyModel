#pragma once
#include <functional>
#include "DynamicDistribution.hpp"
#include <vector>
#include <memory>
#include <string>

using BivariateFunction = std::function<double(double,double)>;
using TrivariateFunction = std::function<double(double,double,double)>;

class StochasticProcess
{
    public:
        StochasticProcess(BivariateFunction driftFunction, BivariateFunction diffusionFunction, BivariateFunction jumpIntensity, std::unique_ptr<DynamicDistribution> jumpSizeDistribution);
        virtual ~StochasticProcess() = default;
        double getDrift(double t, double x_t);
        double getDiffusion(double t, double x_t);
        double getJump(double t_prev, double t_new, double x_t_prev, std::mt19937& generator);
        BivariateFunction getDriftFunction();
        BivariateFunction getDiffusionFunction();
        BivariateFunction getJumpIntensityFunction();
        virtual std::string getStringParameters() = 0;
    protected:
        BivariateFunction driftFunction_;
        BivariateFunction diffusionFunction_;
        BivariateFunction jumpIntensity_;
        std::unique_ptr<DynamicDistribution> jumpSizeDistribution_;
        std::poisson_distribution<int> jumpCountDistribution_;

};