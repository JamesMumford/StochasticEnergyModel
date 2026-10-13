#pragma once
#include "StochasticProcess.hpp"
#include "Solver.hpp"

class EulerMaruyama : public Solver
{
    public:
        EulerMaruyama(StochasticProcess& process, double dt, unsigned int seed);
        double step(double t, double x_t) override;
        void writeSimulationParams(std::string filename, unsigned int steps, unsigned int sims, double t_0, double x_t_0) override;
};