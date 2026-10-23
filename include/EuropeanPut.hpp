#pragma once
#include "Option.hpp"

class EuropeanPut : public Option
{
    public:
        EuropeanPut(std::unique_ptr<Solver> processSolver, double t_0, double x_t_0, double strike, unsigned int stepsToExpiry);
        double EstimateValueMonteCarlo(double riskFreeRate, unsigned int stepsToExpiry) override;
        std::vector<double> EstimateConfidenceIntervalMonteCarlo(double riskFreeRate, double confidence, unsigned int stepsToExpiry) override;
    private:
        double Payoff(double riskFreeRate, double underlyingPrice);
};