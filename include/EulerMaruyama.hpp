#pragma once
#include "StochasticProcess.hpp"
#include <random>
#include <vector>
using std::vector;

class EulerMaruyama
{
    private:
        StochasticProcess& process_;
        double dt_;
        std::mt19937 randomGenerator_;
        std::normal_distribution<double> normalDist_;
    public:
        EulerMaruyama(StochasticProcess& process, double dt, unsigned int seed);
        double step(double t, double x_t);
        double simulatePath(double t_0, double x_t_0, int no_steps);
        vector<double> simulatePathHistory(double t_0, double x_t_0, int no_steps);
};