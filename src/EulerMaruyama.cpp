#include "EulerMaruyama.hpp"
#include <iostream>

EulerMaruyama::EulerMaruyama(StochasticProcess& process, double dt, unsigned int seed) : Solver
(
    process,
    dt,
    seed
){};

double EulerMaruyama::step(double t, double x_t)
{
    double dB_t = (*std::make_unique<Normal>(0,1)).sample(generator_) * sqrt(dt_);
    return x_t + process_.getDrift(t, x_t) * dt_ + process_.getDiffusion(t,x_t) * dB_t + process_.getJump(t, t + dt_, x_t, generator_);
};

void EulerMaruyama::writeSimulationParams(std::string filename, unsigned int steps, unsigned int sims, double t_0, double x_t_0)
{
    std::ofstream file(filename);
    file << "NUMBER OF SIMS = " + std::to_string(sims) + ", NUMBER OF STEPS PER SIM = " + std::to_string(steps) + "\n";
    file << "RANDOM START SEED = " + std::to_string(seed_) + "\n";
    file << "DELTA T = " + std::to_string(getDt()) + "\n";
    file << "T IN: [" + std::to_string(t_0) + ", " + std::to_string(t_0 + steps * getDt()) + "]\n";
    file << "X_T_0 = " + std::to_string(x_t_0) + "\n";
    file << process_.getStringParameters();
}
