#pragma once
#include "OrnsteinUhlenbeck.hpp"
#include <random>

class EulerMaruyama
{
    private:
        OrnsteinUhlenbeck& process_;
        double dt_;
        std::mt19937 randomGenerator_;
        std::normal_distribution<double> normalDist_;
    public:
        EulerMaruyama(OrnsteinUhlenbeck& process, double dt, unsigned int seed);
        double step(double x_t);
};