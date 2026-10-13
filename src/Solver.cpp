#include "Solver.hpp"

Solver::Solver(StochasticProcess& process, double dt, unsigned int seed) : process_(process), dt_(dt), generator_(seed), standardNormalDist_(0,1), seed_(seed){};

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

void Solver::simulateAndWritePathHistory(std::string filename, double t_0, double x_t_0, const unsigned int no_steps)
{
    std::vector<double> results = simulatePathHistory(t_0, x_t_0, no_steps);
    std::ofstream file(filename,std::ios::app);

    for (double entry : results)
    {
        file << std::to_string(entry) + ", ";
    }
    file << "\n";
}

double Solver::getDt()
{
    return dt_;
}