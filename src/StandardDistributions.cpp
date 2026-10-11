#include "StandardDistributions.hpp"

DiracDelta::DiracDelta(double x) : x_(x){};
double DiracDelta::sample(std::mt19937& generator)
{
    return x_;
}

Exponential::Exponential(double lambda) : distribution_(std::exponential_distribution<double>(lambda)){};
double Exponential::sample(std::mt19937& generator) 
{
    return distribution_(generator);
}

Normal::Normal(double mu, double sigma) : distribution_(std::normal_distribution<double>(mu,sigma)){};
double Normal::sample(std::mt19937& generator)
{
    return distribution_(generator);
}

AbsoluteNormal::AbsoluteNormal(double mu, double sigma) : distribution_(std::normal_distribution<double>(mu,sigma)){};
double AbsoluteNormal::sample(std::mt19937& generator)
{
    return std::abs(distribution_(generator));
}

namespace StandardDistributions
{
    DiracDelta zeroDirac = DiracDelta(0);
    DiracDelta infinityDirac = DiracDelta(std::numeric_limits<double>::infinity());
}
