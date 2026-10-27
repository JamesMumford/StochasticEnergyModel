#include "CompositeSolver.hpp"

CompositeSolver::CompositeSolver(std::vector<std::unique_ptr<Solver>> solvers)
{
    solvers_ = std::move(solvers);
};

std::vector<double> CompositeSolver::step(double t, std::vector<double> x_t)
{
    int solverNo = x_t.size();
    std::vector<double> next = x_t;
    for (int i = 0; i < solverNo; i++)
    {
        next.at(i) = solvers_.at(i)->step(t,x_t.at(i));
    }
    return next;
}

std::vector<double> CompositeSolver::simulatePath(double t_0, std::vector<double> x_t_0, const unsigned int no_steps)
{
    int solverNo = x_t_0.size();
    double dt = solvers_.at(0)->getDt();
    std::vector<double> x_T = x_t_0;
    for (int i = 0; i < no_steps; i++)
    {
        for (int j = 0; j < solverNo; j++)
        {
            x_T.at(j) = solvers_.at(i)->step(t_0 + i * dt, x_T.at(j));
        }
    }
    return x_T;
}

std::vector<std::vector<double>> CompositeSolver::simulatePathHistory(double t_0, std::vector<double> x_t_0, const unsigned int no_steps)
{
    int noSolvers = x_t_0.size();
    double dt = solvers_.at(0)->getDt();
    std::vector<std::vector<double>> stateHistory(no_steps+1);
    stateHistory.at(0) = x_t_0;
    for (int i = 0; i < no_steps; i++)
    {
        stateHistory.at(i+1) = step(t_0 + i * dt, stateHistory.at(i));
    }
    return stateHistory;
}

void CompositeSolver::simulateAndWritePathHistory(std::string filename, double t_0, std::vector<double> x_t_0, const unsigned int no_steps)
{
    std::vector<std::vector<double>> results = simulatePathHistory(t_0, x_t_0, no_steps);
    std::ofstream file(filename,std::ios::app);
    for (std::vector<double> entry : results)
    {
        double terminalValue = 0;
        for (double component : entry)
        {
            terminalValue += component;
        }
        file << std::to_string(terminalValue) + ", ";
    }
    file << "\n";
}