#include "StandardDistributions.hpp"

DiracDelta::DiracDelta(double x) : x_(x){};
double DiracDelta::sample()
{
    return x_;
}

Distribution zeroDirac = DiracDelta(0);
Distribution infinityDirac = DiracDelta(std::numeric_limits<double>::infinity());