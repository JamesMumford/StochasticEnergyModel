#pragma once
#include "StochasticProcess.hpp"
#include "StandardDistributions.hpp"

class OrnsteinUhlenbeck : public StochasticProcess
{
    public:
        OrnsteinUhlenbeck(double theta, double mu, double sigma);

    private:
        double theta_;
        double mu_;
        double sigma_;
};