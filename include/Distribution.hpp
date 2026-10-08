#pragma once
#include <limits>

class Distribution
{
    public:
        virtual ~Distribution();
        virtual double sample();
    private:
};