#pragma once
#include "Distribution.hpp"
#include "StochasticProcess.hpp"

class PureJumpProcess : public StochasticProcess
{
    public:
        PureJumpProcess(BivariateFunction jumpIntensity, std::unique_ptr<Distribution> jumpSizeDistribution);
        std::string getStringParameters() override;
};