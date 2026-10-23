#include "EuropeanCall.hpp"

EuropeanCall::EuropeanCall(std::unique_ptr<Solver> processSolver, double t_0, double x_t_0, double strike, unsigned int stepsToExpiry) : Option(std::move(processSolver),t_0,x_t_0,strike,stepsToExpiry){};

double EuropeanCall::Payoff(double riskFreeRate, double finalUnderlyingPrice)
{
    if (finalUnderlyingPrice > strike_)
    {
        return exp(-riskFreeRate * stepsToExpiry_ * (*processSolver_).getDt()) * (finalUnderlyingPrice - strike_);
    }
    return 0;
}