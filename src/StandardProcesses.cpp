#include "StandardProcesses.hpp"


PoissonProcess::PoissonProcess(double intensity, double scale) : PureJumpProcess
(
    [intensity](double t, double x_t){ return intensity; },
    std::make_unique<DiracDelta>(scale)
){};

std::string PoissonProcess::getStringParameters()
{
    return "Poisson Process: INTENSITY = " + std::to_string(jumpIntensity_(0,0)) + ", SCALE: " + std::to_string((*jumpSizeDistribution_).sample()) + "\n";
}