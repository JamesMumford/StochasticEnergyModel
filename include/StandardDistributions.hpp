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
        std::exponential_distribution<double> distribution_;
};

class Normal : public Distribution
{
    public:
        Normal(double mu, double sigma);
        double sample(std::mt19937& generator) override;
    private:
        std::normal_distribution<double> distribution_;
};

class AbsoluteNormal : public Distribution
{
    public:
        AbsoluteNormal(double mu, double sigma);
        double sample(std::mt19937& generator) override;
    private:
        std::normal_distribution<double> distribution_;

};

namespace StandardDistributions
{
    extern DiracDelta zeroDirac;
    extern DiracDelta infinityDirac;
}