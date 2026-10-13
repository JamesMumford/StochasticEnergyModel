#include "PureJumpProcess.hpp"

PureJumpProcess::PureJumpProcess(BivariateFunction jumpIntensity, std::unique_ptr<Distribution> jumpSizeDistribution) : StochasticProcess
(
    [](double,double){return 0;},
    [](double,double){return 0;},
    jumpIntensity,
    std::move(jumpSizeDistribution)
){};

std::string PureJumpProcess::getStringParameters()
{
    return "Pure jump process: Pass to child method for more detail";
}