#pragma once
#include <functional>
#include "StochasticProcess.hpp"
#include "EulerMaruyama.hpp"
#include <vector>
#include <string>

namespace Utility
{
    std::vector<double> ParseCSVline(std::string line);

    void writeEulerMaruyamaSim(StochasticProcess& OUref, double T_0, double X_T_0, double resolution, unsigned int noSteps, unsigned int noSims, unsigned int randomSeed);
}