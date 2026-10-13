#include "BrownianMotion.hpp"


BrownianMotion::BrownianMotion(double mu, double sigma) : StochasticProcess
(
            [mu](double, double){return mu;},
            [sigma](double,double){return sigma;},
            [](double,double){return 0;},
            std::make_unique<DiracDelta>(0)
)
{
    mu_ = mu;
    sigma_ = sigma;
};

std::string BrownianMotion::getStringParameters()
{
    return "BM: MU = " + std::to_string(mu_) + ", SIGMA = " + std::to_string(sigma_) + "\n";
}