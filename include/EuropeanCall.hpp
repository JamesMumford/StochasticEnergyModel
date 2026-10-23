#pragma once
#include "Option.hpp"

class EuropeanCall : public Option
{
    public:
        EuropeanCall(std::unique_ptr<Solver> processSolver, double t_0, double x_t_0, double strike, unsigned int stepsToExpiry);
        double EstimateValueMonteCarlo(double riskFreeRate, unsigned int noSims) override;
        std::vector<double> EstimateConfidenceIntervalMonteCarlo(double riskFreeRate, double confidence, unsigned int noSims) override;
    private:
        double Payoff(double riskFreeRate, double finalUnderlyingPrice) override;
};