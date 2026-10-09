#include "BrownianMotion.hpp"


BrownianMotion::BrownianMotion(double mu, double sigma) : StochasticProcess
(
            [mu](double, double){return mu;},
            [sigma](double,double){return sigma;},
            StandardDistributions::infinityDirac,
            StandardDistributions::zeroDirac
){};