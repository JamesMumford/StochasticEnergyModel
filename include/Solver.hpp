#pragma once
#include "StochasticProcess.hpp"
#include "StandardDistributions.hpp"
#include <vector>
#include <random>

class Solver
{
    public:
        Solver(StochasticProcess& process, double dt, unsigned int seed);
        virtual double step(double t, double x_t);
        virtual double simulatePath(double t_0, double x_t_0, const unsigned int no_steps);
        virtual std::vector<double> simulatePathHistory(double t_0, double x_t_0, const unsigned int no_steps);

    protected:
        StochasticProcess& process_;
        std::mt19937 generator_;
        double dt_;
        Normal standardNormalDist_;

};