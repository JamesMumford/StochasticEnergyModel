#pragma once
#include "StochasticProcess.hpp"
#include "StandardDistributions.hpp"

class OrnsteinUhlenbeck : public StochasticProcess
{
    public:
        OrnsteinUhlenbeck(double theta, double mu, double sigma);
        std::string getStringParameters() override;
        double AnalyticEV(unsigned int steps, double X_T_0, double dt);
    private:
        double theta_;
        double mu_;
        double sigma_;
};