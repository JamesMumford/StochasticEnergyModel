#include "OrnsteinUhlenbeck.hpp"

OrnsteinUhlenbeck::OrnsteinUhlenbeck(double theta,double mu,double sigma) : StochasticProcess
(
    [theta,mu](double t, double x_t){return theta * (mu - x_t);},
    [sigma](double,double){return sigma;},
    zeroDirac,
    infinityDirac
){};