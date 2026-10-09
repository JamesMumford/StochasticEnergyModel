#pragma once
#include "Distribution.hpp"
#include <limits>

class DiracDelta : public Distribution
{
    public:
        DiracDelta(double x);
        double sample(std::mt19937& generator) override;
    private:
        double x_;
};

class Exponential : public Distribution
{
    public:
        Exponential(double lambda);
        double sample(std::mt19937& generator) override;
    private:
        double lambda_;
        std::exponential_distribution<double> distribution_;
};

class Normal : public Distribution
{
    public:
        Normal(double mu, double sigma);
        double sample(std::mt19937& generator) override;
    private:
        double mu_;
        double sigma_;
        std::normal_distribution<double> distribution_;
};

namespace StandardDistributions
{
    extern DiracDelta zeroDirac;
    extern DiracDelta infinityDirac;
}