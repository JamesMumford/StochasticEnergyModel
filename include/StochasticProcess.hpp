#pragma once
#include <functional>
#include "Distribution.hpp"
#include <vector>
#include <memory>
#include <string>

using BivariateFunction = std::function<double(double,double)>;

class StochasticProcess
{
    public:
        StochasticProcess(BivariateFunction driftFunction, BivariateFunction diffusionFunction, BivariateFunction jumpIntensity, std::unique_ptr<Distribution> jumpSizeDistribution);
        virtual ~StochasticProcess() = default;
        double getDrift(double t, double x_t);
        double getDiffusion(double t, double x_t);
        double getJump(double t_prev, double t_new, double x_t_prev, std::mt19937& generator);
        std::function<double(double,double)> getDriftFunction();
        std::function<double(double,double)> getDiffusionFunction();
        std::function<double(double,double)> getJumpIntensityFunction();
        Distribution& getJumpSizeDistribution();
        virtual std::string getStringParameters() = 0;
    protected:
        BivariateFunction driftFunction_;
        BivariateFunction diffusionFunction_;
        BivariateFunction jumpIntensity_;
        std::unique_ptr<Distribution> jumpSizeDistribution_;
        std::poisson_distribution<int> jumpCountDistribution_;

};