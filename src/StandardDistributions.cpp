#include "StandardDistributions.hpp"

DiracDelta::DiracDelta(double x)
{
    init({x});
}
void DiracDelta::init(std::vector<double> parameters)
{
    if (parameters.size() != 1)
    {
        return;
    }
    parameters_ = parameters;
}
double DiracDelta::sample(std::mt19937& generator)
{
    return parameters_.at(0);
}
double DiracDelta::sample()
{
    return parameters_.at(0);
}

Exponential::Exponential(double lambda) : distribution_(std::exponential_distribution<double>(lambda)){};
double Exponential::sample(std::mt19937& generator) 
{
    return distribution_(generator);
}
void Exponential::init(std::vector<double> parameters)
{
    if (parameters.size() != 1)
    {
        return;
    }
    parameters_ = parameters;
    distribution_ = std::exponential_distribution<double>(parameters.at(0));
}
double Exponential::sample()
{
    return 0;
}

Normal::Normal(double mu, double sigma)
{
    init({mu,sigma});
};
double Normal::sample(std::mt19937& generator)
{
    return distribution_(generator);
}
void Normal::init(std::vector<double> parameters)
{
    if (parameters.size() != 2)
    {
        return;
    }
    parameters_ = parameters;
    distribution_ = std::normal_distribution<double>(parameters.at(0),parameters.at(1));
}
double Normal::sample()
{
    return 0;
}

AbsoluteNormal::AbsoluteNormal(double mu, double sigma)
{
    init({mu,sigma});
};
double AbsoluteNormal::sample(std::mt19937& generator)
{
    return std::abs(distribution_(generator));
}
void AbsoluteNormal::init(std::vector<double> parameters)
{
    if (parameters.size() != 2)
    {
        return;
    }
    parameters_ = parameters;
    distribution_ = std::normal_distribution<double>(parameters.at(0),parameters.at(1));
}
double AbsoluteNormal::sample()
{
    return 0;
}
