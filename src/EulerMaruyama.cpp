#include "EulerMaruyama.hpp"

EulerMaruyama::EulerMaruyama(OrnsteinUhlenbeck& process, double dt, unsigned int seed) 
: process_(process), dt_(dt), randomGenerator_(seed), normalDist_(0,1){};

double EulerMaruyama::step(double x_t)
{
    double normal = normalDist_(randomGenerator_);
    double dB_t = normal * sqrt(dt_);
    return process_.drift(x_t) * dt_ + process_.diffusion(x_t) * dB_t;
};