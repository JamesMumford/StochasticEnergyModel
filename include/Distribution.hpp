#pragma once
#include <limits>

class Distribution
{
    public:
        virtual ~Distribution() = default;
        virtual double sample();
    private:
};