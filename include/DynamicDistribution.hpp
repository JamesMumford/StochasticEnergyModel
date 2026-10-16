#pragma once
#include "Distribution.hpp"
#include <functional>
#include <vector>
#include <memory>

using ParameterFunction = std::function<std::vector<double>(double, double)>;

class DynamicDistribution
{
    public:
        DynamicDistribution(std::unique_ptr<Distribution> distribution, ParameterFunction parameterFunction);
        double sample(double t, double x_t, std::mt19937& generator);
        double staticSample(std::mt19937& generator);
    private:
        ParameterFunction parameterFunction_;
        std::unique_ptr<Distribution> distribution_;
};