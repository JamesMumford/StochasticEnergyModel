#include "Solver.hpp"

Solver::Solver(StochasticProcess& process, double dt, unsigned int seed) : process_(process), dt_(dt), generator_(seed), standardNormalDist_(0,1)
{
    process.setJumpWait(generator_);
};

/* Euler-Murayama stepping implementation for now, generalise later*/
double Solver::step(double t, double x_t)
{
    return 0;
}

double Solver::simulatePath(double t_0, double x_t_0, const unsigned int no_steps)
{
    double x_T = x_t_0;
    for (int i = 0; i < no_steps; i++)
    {
        x_T = step(t_0 + i * dt_, x_t_0);
    }
    return x_T;
}

std::vector<double> Solver::simulatePathHistory(double t_0, double x_t_0, const unsigned int no_steps)
{
    std::vector<double> stateHistory(no_steps+1);
    stateHistory.at(0) = x_t_0;
    for (int i = 0; i < no_steps; i++)
    {
        stateHistory.at(i+1) = step(t_0 + i * dt_, stateHistory.at(i));
    }
    return stateHistory;
}