#pragma once
#include "Distribution.hpp"
#include "StochasticProcess.hpp"

class PureJumpProcess : public StochasticProcess
{
    public:
        PureJumpProcess(Distribution& jumpWaitingDistribution, Distribution& jumpSizeDistribution);
};