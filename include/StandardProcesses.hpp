#pragma once
#include "StochasticProcess.hpp"
#include "PureJumpProcess.hpp"
#include "StandardDistributions.hpp"

class PoissonProcess : public PureJumpProcess
{
    public:
        PoissonProcess(double intensity, double scale);
};