#pragma once
#include "Solver.hpp"

class CompositeSolver
{
    public:
        CompositeSolver(std::vector<std::unique_ptr<Solver>> solvers);
        std::vector<double> step(double t, std::vector<double> x_t);
        std::vector<double> simulatePath(double t_0, std::vector<double> x_t_0, const unsigned int no_steps);
        std::vector<std::vector<double>> simulatePathHistory(double t_0, std::vector<double> x_t_0, const unsigned int no_steps);
        void simulateAndWritePathHistory(std::string filename, double t_0, std::vector<double> x_t_0, const unsigned int no_steps);
        double getDt();
    private:
        std::vector<std::unique_ptr<Solver>> solvers_;
};