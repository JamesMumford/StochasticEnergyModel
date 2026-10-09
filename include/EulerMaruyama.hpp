#pragma once
#include "StochasticProcess.hpp"
#include "Solver.hpp"

class EulerMaruyama : public Solver
{
    public:
        EulerMaruyama(StochasticProcess& process, double dt, unsigned int seed);
        double step(double t, double x_t) override;
};