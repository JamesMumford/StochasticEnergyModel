#include "EulerMaruyama.hpp"

EulerMaruyama::EulerMaruyama(OrnsteinUhlenbeck& process, double dt, unsigned int seed) 
: process_(process), dt_(dt), randomGenerator_(seed), normalDist_(0,1){};

double EulerMaruyama::step(double x_t)
{
    double normal = normalDist_(randomGenerator_);
    double dB_t = normal * sqrt(dt_);
    return x_t + process_.drift(x_t) * dt_ + process_.diffusion(x_t) * dB_t;
};

double EulerMaruyama::simulatePath(double x_t, int no_steps)
{
    for (int i = 0; i < no_steps; i++)
    {
        x_t = step(x_t);
    }
    return x_t;
}

vector<double> EulerMaruyama::simulatePathHistory(double x_t, int no_steps)
{
    vector<double> stateHistory(no_steps+1);
    stateHistory.at(0) = x_t;
    for (int i = 0; i < no_steps; i++)
    {
        stateHistory.at(i+1) = step(stateHistory.at(i));
    }
    return stateHistory;
}