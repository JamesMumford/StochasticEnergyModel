#pragma once
#include "StochasticProcess.hpp"
#include "StandardDistributions.hpp"

class BrownianMotion : public StochasticProcess
{
    public:
        BrownianMotion(double mu, double sigma);
    private:
        double mu_;
        double sigma_;

};