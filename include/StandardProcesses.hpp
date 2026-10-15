#pragma once
#include "StochasticProcess.hpp"
#include "PureJumpProcess.hpp"
#include "StandardDistributions.hpp"

class PoissonProcess : public PureJumpProcess
{
    public:
        PoissonProcess(double intensity, double scale);
        std::string getStringParameters() override;
    private:
        double intensity_;
        double scale_;
};

class ProportionalPureJumpProcess : public PureJumpProcess
{
    public:
        ProportionalPureJumpProcess(double intensityGradient, double scale);
        std::string getStringParameters() override;
    private:
        double intensityGradient_;
        double scale_;
};