#pragma once
#include "StochasticProcess.hpp"
#include "StandardDistributions.hpp"
#include <vector>
#include <random>
#include <iostream>
#include <fstream>

class Solver
{
    public:
        Solver(StochasticProcess& process, double dt, unsigned int seed);
        virtual double step(double t, double x_t);
        virtual double simulatePath(double t_0, double x_t_0, const unsigned int no_steps);
        virtual std::vector<double> simulatePathHistory(double t_0, double x_t_0, const unsigned int no_steps);
        virtual void writeSimulationParams(std::string filename, unsigned int steps, unsigned int sims, double t_0, double x_t_0) = 0;
        void simulateAndWritePathHistory(std::string filename, double t_0, double x_t_0, const unsigned int no_steps);
        double getDt();
        const unsigned int seed_;

    protected:
        StochasticProcess& process_;
        std::mt19937 generator_;
        double dt_;
        Normal standardNormalDist_;

};