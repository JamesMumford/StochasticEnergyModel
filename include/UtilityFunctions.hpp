#pragma once
#include <functional>
#include "StochasticProcess.hpp"

namespace UtilityFunctions
{
    BivariateFunction AddBivarFunc(const std::vector<std::function<double(double,double)>>& funcs, std::vector<double> weights);

};