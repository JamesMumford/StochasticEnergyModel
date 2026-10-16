#include "OrnsteinUhlenbeck.hpp"

OrnsteinUhlenbeck::OrnsteinUhlenbeck(double theta,double mu,double sigma) : StochasticProcess
(
    [theta,mu](double t, double x_t){return theta * (mu - x_t);},
    [sigma](double,double){return sigma;},
    [](double,double){return 0;},
    std::make_unique<DynamicDistribution>(std::make_unique<DiracDelta>(0),[](double,double){return std::vector<double>{0,0};})
)
{
    theta_ = theta;
    mu_ = mu;
    sigma_ = sigma;
};

std::string OrnsteinUhlenbeck::getStringParameters()
{
    return "Ornstein Uhlenbeck: THETA = " + std::to_string(theta_) + ", MU = " + std::to_string(mu_) + ", SIGMA = " + std::to_string(sigma_) + "\n";
}

double OrnsteinUhlenbeck::AnalyticEV(unsigned int steps, double X_T_0, double dt)
{
    return X_T_0 * exp(-theta_ * dt * steps) + mu_ * (1 - exp(-theta_ * dt * steps));
}