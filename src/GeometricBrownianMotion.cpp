#include "GeometricBrownianMotion.hpp"

GeometricBrownianMotion::GeometricBrownianMotion(double mu, double sigma): StochasticProcess
(
    [mu](double t, double x_t){return mu * x_t;},
    [sigma](double t,double x_t){return sigma * x_t;},
    zeroDirac,
    infinityDirac
 ){};