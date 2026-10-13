#pragma once
#include "StochasticProcess.hpp"
#include "StandardDistributions.hpp"

class BrownianMotion : public StochasticProcess
{
    public:
        BrownianMotion(double mu, double sigma);
        std::string getStringParameters() override;
    private:
        double mu_;
        double sigma_;

};