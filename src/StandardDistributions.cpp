#include "StandardDistributions.hpp"

DiracDelta::DiracDelta(double x) : x_(x){};
double DiracDelta::sample(std::mt19937& generator)
{
    return x_;
}

Exponential::Exponential(double lambda) : lambda_(lambda){};
double Exponential::sample(std::mt19937& generator)
{
    return distribution_(generator);
}

Normal::Normal(double mu, double sigma) : mu_(mu), sigma_(sigma){};
double Normal::sample(std::mt19937& generator)
{
    return distribution_(generator);
}

namespace StandardDistributions
{
    DiracDelta zeroDirac = DiracDelta(0);
    DiracDelta infinityDirac = DiracDelta(std::numeric_limits<double>::infinity());
}
