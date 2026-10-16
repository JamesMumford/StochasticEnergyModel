#pragma once
#include <limits>
#include <random>

class Distribution
{
    public:
        virtual ~Distribution() = default;
        virtual double sample(std::mt19937& generator) = 0;
        virtual double sample() = 0;
        virtual void init(std::vector<double> parameters) = 0;
        virtual std::vector<double> getParameters();
    protected:
        std::vector<double> parameters_;
};