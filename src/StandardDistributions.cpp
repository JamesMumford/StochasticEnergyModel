#include "StandardDistributions.hpp"

DiracDelta::DiracDelta(double x) : x_(x){};
double DiracDelta::sample(std::mt19937& generator)
{
    return x_;
}
double DiracDelta::sample()
{
    return x_;
}

Exponential::Exponential(double lambda) : distribution_(std::exponential_distribution<double>(lambda)){};
double Exponential::sample(std::mt19937& generator) 
{
    return distribution_(generator);
}
double Exponential::sample()
{
    return 0;
}

Normal::Normal(double mu, double sigma) : distribution_(std::normal_distribution<double>(mu,sigma)){};
double Normal::sample(std::mt19937& generator)
{
    return distribution_(generator);
}
double Normal::sample()
{
    return 0;
}

AbsoluteNormal::AbsoluteNormal(double mu, double sigma) : distribution_(std::normal_distribution<double>(mu,sigma)){};
double AbsoluteNormal::sample(std::mt19937& generator)
{
    return std::abs(distribution_(generator));
}
double AbsoluteNormal::sample()
{
    return 0;
}
