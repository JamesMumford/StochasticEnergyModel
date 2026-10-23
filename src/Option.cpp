#include "Option.hpp"

Option::Option(std::unique_ptr<Solver> processSolver, double t_0, double x_t_0, double strike, unsigned int stepsToExpiry)
{
    processSolver_ = std::move(processSolver);
    t_0_ = t_0;
    x_t_0_ = x_t_0;
    strike_ = strike;
    stepsToExpiry_ = stepsToExpiry;
    standardNormal_ = boost::math::normal(0,1);
}

double Option::EstimateValueMonteCarlo(double riskFreeRate, unsigned int noSims)
{
    std::vector<double> terminalValues(noSims);
    double mean = 0;
    for (int i = 0; i < noSims; i++)
    {
        terminalValues[i] = (*processSolver_).simulatePath(t_0_,x_t_0_,stepsToExpiry_);
        mean += Payoff(riskFreeRate,terminalValues[i]);
    }
    mean /= noSims;
    return mean;
}

std::vector<double> Option::EstimateConfidenceIntervalMonteCarlo(double riskFreeRate, double confidence, unsigned int noSims)
{
    std::vector<double> terminalValues(noSims);
    double mean = 0;
    double variance = 0;
    double stdev = 0;
    double payoff = 0;
    for (int i = 0; i < noSims; i++)
    {
        terminalValues[i] = (*processSolver_).simulatePath(t_0_,x_t_0_,stepsToExpiry_);
        payoff = Payoff(riskFreeRate,terminalValues[i]);
        mean += payoff;
    }
    mean /= noSims;
    for (int i = 0; i < noSims; i++)
    {
        variance += (terminalValues[i] - mean) * (terminalValues[i] - mean);
    }
    variance /= noSims;
    stdev = sqrt(variance);
    double standardQuantile = boost::math::quantile(standardNormal_,1 - 0.5 * confidence);
    return std::vector<double>{standardQuantile * stdev + mean, -standardQuantile * stdev + mean};
}