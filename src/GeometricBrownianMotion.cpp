#include "GeometricBrownianMotion.hpp"

GeometricBrownianMotion::GeometricBrownianMotion(double mu, double sigma): StochasticProcess
(
    [mu](double t, double x_t){return mu * x_t;},
    [sigma](double t,double x_t){return sigma * x_t;},
    [](double,double){return 0;},
    std::make_unique<DynamicDistribution>(std::make_unique<DiracDelta>(0),[](double,double){return std::vector<double>{0,0};})
 )
 {
    mu_ = mu;
    sigma_ = sigma;
 };

 std::string GeometricBrownianMotion::getStringParameters()
 {
    return "GBM: MU = " + std::to_string(mu_) + ", SIGMA = " + std::to_string(sigma_) + "\n";
 }