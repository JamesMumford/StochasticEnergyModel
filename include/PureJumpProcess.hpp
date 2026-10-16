#pragma once
#include "Distribution.hpp"
#include "StochasticProcess.hpp"

class PureJumpProcess : public StochasticProcess
{
    public:
        PureJumpProcess(BivariateFunction jumpIntensity, std::unique_ptr<DynamicDistribution> jumpSizeDistribution);
        std::string getStringParameters() override;
};