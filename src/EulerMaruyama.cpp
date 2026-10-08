#include "EulerMaruyama.hpp"

EulerMaruyama::EulerMaruyama(StochasticProcess& process, double dt, unsigned int seed) 
: process_(process), dt_(dt), randomGenerator_(seed), normalDist_(0,1){};

double EulerMaruyama::step(double t, double x_t)
{
    double normal = normalDist_(randomGenerator_);
    double dB_t = normal * sqrt(dt_);
    return x_t + process_.getDrift(t, x_t) * dt_ + process_.getDiffusion(t, x_t) * dB_t;
};

double EulerMaruyama::simulatePath(double t_0, double x_t_0, const int no_steps)
{
    double x_T = x_t_0;
    for (int i = 0; i < no_steps; i++)
    {
        x_T = step(t_0 + i * dt_, x_t_0);
    }
    return x_T;
}

vector<double> EulerMaruyama::simulatePathHistory(double t_0, double x_t_0, const int no_steps)
{
    vector<double> stateHistory(no_steps+1);
    stateHistory.at(0) = x_t_0;
    for (int i = 0; i < no_steps; i++)
    {
        stateHistory.at(i+1) = step(t_0 + i * dt_, stateHistory.at(i));
    }
    return stateHistory;
}