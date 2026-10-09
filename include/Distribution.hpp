#pragma once
#include <limits>
#include <random>

class Distribution
{
    public:
        virtual ~Distribution() = default;
        virtual double sample(std::mt19937& generator);
    private:
};