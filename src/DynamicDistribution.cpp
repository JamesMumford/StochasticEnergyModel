#include "DynamicDistribution.hpp"

DynamicDistribution::DynamicDistribution(std::unique_ptr<Distribution> distribution, ParameterFunction parameterFunction) : distribution_(std::move(distribution)), parameterFunction_(parameterFunction){};
double DynamicDistribution::sample(double t, double x_t, std::mt19937& generator)
{
    (*distribution_).init(parameterFunction_(t,x_t));
    return (*distribution_).sample(generator);
}
double DynamicDistribution::staticSample(std::mt19937& generator)
{
    return (*distribution_).sample(generator);
}
