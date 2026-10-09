#include "EulerMaruyama.hpp"

EulerMaruyama::EulerMaruyama(StochasticProcess& process, double dt, unsigned int seed) : Solver
(
    process,
    dt,
    seed
){};

double EulerMaruyama::step(double t, double x_t)
{
    double normal = standardNormalDist_.sample(generator_);
    double dB_t = normal * sqrt(dt_);
    return x_t + process_.getDrift(t, x_t) * dt_ + process_.getDiffusion(t,x_t) * dB_t + process_.getJump(t, t + dt_, generator_);
};
