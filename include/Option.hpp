#include "Solver.hpp"
#include <boost/math/distributions/normal.hpp>

class Option
{
    public:
        Option(std::unique_ptr<Solver> processSolver, double t_0, double x_t_0, double strike, unsigned int stepsToExpiry);
        virtual double EstimateValueMonteCarlo(double riskFreeRate, unsigned int noSims);
        virtual std::vector<double> EstimateConfidenceIntervalMonteCarlo(double riskFreeRate, double confidence, unsigned int noSims);
    protected:
        virtual double Payoff(double riskFreeRate, double finalUnderlyingPrice);
        std::unique_ptr<Solver> processSolver_;
        double t_0_;
        double x_t_0_;
        double strike_;
        unsigned int stepsToExpiry_;
        boost::math::normal standardNormal_;
};