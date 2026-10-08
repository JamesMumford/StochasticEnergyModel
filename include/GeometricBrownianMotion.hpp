#pragma once
#include "StochasticProcess.hpp"
#include "StandardDistributions.hpp"

class GeometricBrownianMotion : public StochasticProcess
{
    public:
        GeometricBrownianMotion(double mu, double sigma);

        double drift(double x_t);
        double diffusion(double x_t);

    private:
        double mu_;
        double sigma_;
};