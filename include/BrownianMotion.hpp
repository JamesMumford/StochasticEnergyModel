#pragma once
#include "StochasticProcess.hpp"
#include "DiracDelta.hpp"

DiracDelta infinityDirac(std::numeric_limits<double>::infinity());
DiracDelta zeroDirac(0);

class BrownianMotion : public StochasticProcess
{
    public:
        BrownianMotion(double mu, double sigma) : StochasticProcess(
            [mu](double, double){return mu;},
            [sigma](double,double){return sigma;},
            infinityDirac,
            zeroDirac
        ){};

    private:
        double mu_;
        double sigma_;

};