#pragma once
#include "OrnsteinUhlenbeck.hpp"
#include <random>
#include <vector>
using std::vector;

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
        double simulatePath(double x_t, int no_steps);
        vector<double> simulatePathHistory(double x_t, int no_steps);
};