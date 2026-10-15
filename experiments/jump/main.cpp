#include "EulerMaruyama.hpp"
#include "PureJumpProcess.hpp"
#include "StandardDistributions.hpp"
#include "Distribution.hpp"
#include "StandardProcesses.hpp"
#include "UtilityFunctions.hpp"
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
const double scale = 1.0;
const double proportionalityIntensity = 0.03;
const double fixedIntensity = 2;

void writeEulerMaruyamaPoissonProcess(double,double);
void writeEulerMaruyamaProportionalJumpProcess(double, double);

int main()
{
    std::cout << "Proportional intensity jump process (EM).\n";
    writeEulerMaruyamaProportionalJumpProcess(proportionalityIntensity, 1);
    std::cout << "Fixed intensity (Poisson) jump process (EM).\n";
    writeEulerMaruyamaPoissonProcess(fixedIntensity,1);
}

void writeEulerMaruyamaPoissonProcess(double intensity, double scale)
{
    PoissonProcess process(intensity, scale);
    StochasticProcess& processRef = process;
    Utility::writeEulerMaruyamaSim(processRef,T_0, X_T_0, resolution, noSteps, noSims, randomSeed);
}

void writeEulerMaruyamaProportionalJumpProcess(double intensityGradient, double scale)
{
    ProportionalPureJumpProcess process(intensityGradient, scale);
    StochasticProcess& processRef = process;
    Utility::writeEulerMaruyamaSim(processRef,T_0, X_T_0, resolution, noSteps, noSims, randomSeed);

}

double predictJumpEV(StochasticProcess& Jumpref)
{
    std::vector<double> terminalValues(noSims);

    for (int i = 0; i < noSims; i++)
    {
        EulerMaruyama JumpSolver(Jumpref,resolution,randomSeed + i);
        terminalValues[i] = JumpSolver.simulatePath(T_0, X_T_0, noSteps);
    }

    double sum = 0;
    for (double num : terminalValues)
    {
        sum += num;
    }

    return sum / noSims;
}