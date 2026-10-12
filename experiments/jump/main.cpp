#include "EulerMaruyama.hpp"
#include "PureJumpProcess.hpp"
#include "StandardDistributions.hpp"
#include "Distribution.hpp"
#include <iostream>
#include <random>
#include <fstream>

double predictJumpEV(StochasticProcess&);

/* Simulation parameters*/
const int noSteps = 50;
const unsigned int randomSeed = 770;
const double resolution = 0.1;
const int noSims = 100;
const double T_0 = 0;
const double X_T_0 = 100;

/* Pure jump process parameters */
double INTENSITY_LAMBDA = 0.1;
const double JUMP_SIZE_MU = 0;
const double JUMP_SIZE_SIGMA = 25;
const double X_0 = 0.0;

int main()
{
    PureJumpProcess jumpProcess
    (
        [](double,double){return INTENSITY_LAMBDA;},
         std::move(std::make_unique<Normal>(JUMP_SIZE_MU,JUMP_SIZE_SIGMA))
    );

    std::string filename;
    std::cout << "\nStore results in file: ";
    std::cin >> filename;

    std::ofstream file("results/ou/"+filename + ".csv");

    file << "FIXED JUMP INTENSITY = " << INTENSITY_LAMBDA << ", MEAN JUMP SIZE = " << JUMP_SIZE_MU << ", STDEV OF JUMP SIZE = " << JUMP_SIZE_SIGMA << ", T_0 =" << T_0 << ", X_T_0 = " << X_T_0 << ", DELTA T = " << resolution << "\n";
    file << "RANDOM SEEDS: " + std::to_string(randomSeed) + " + i\n";
    file << "NUMBER OF SIMS = " + std::to_string(noSims) + ", NUMBER OF STEPS PER SIM = " + std::to_string(noSteps) + "\n";

    for (int i = 0; i < noSims; i++)
    {
        EulerMaruyama jumpSolver(jumpProcess,resolution,randomSeed + i);
        std::vector<double> results = jumpSolver.simulatePathHistory(T_0, X_T_0, noSteps);
        for (double num : results)
        {
            file << num << ", ";
        }
        file << "\n";
    }




}

double predictJumpEV(StochasticProcess& Jumpref)
{
    std::vector<double> terminalValues(noSims);

    for (int i = 0; i < noSims; i++)
    {
        EulerMaruyama JumpSolver(Jumpref,resolution,randomSeed + i);
        terminalValues[i] = JumpSolver.simulatePath(0,X_0,noSteps);
    }

    double sum = 0;
    for (double num : terminalValues)
    {
        sum += num;
    }

    return sum / noSims;
}