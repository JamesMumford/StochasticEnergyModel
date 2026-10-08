#pragma once
#include "Distribution.hpp"
#include <limits>

class DiracDelta : public Distribution
{
    public:
        DiracDelta(double x);
        double sample() override;
    private:
        double x_;
};