#include "StandardProcesses.hpp"


PoissonProcess::PoissonProcess(double intensity, double scale) : PureJumpProcess
(
    [intensity](double t, double x_t){ return intensity; },
    std::make_unique<DynamicDistribution>(std::make_unique<DiracDelta>(scale),[scale](double,double){return std::vector<double>{scale};})
){};

std::string PoissonProcess::getStringParameters()
{
    return "Poisson Process: INTENSITY = " + std::to_string(intensity_) + ", SCALE: " + std::to_string(scale_) + "\n";
}

ProportionalPureJumpProcess::ProportionalPureJumpProcess(double intensityGradient, double scale) : PureJumpProcess
(
    [intensityGradient](double t, double x_t){return intensityGradient * x_t;},
    std::make_unique<DynamicDistribution>(std::make_unique<DiracDelta>(scale),[scale](double,double){return std::vector<double>{scale};})
){};

std::string ProportionalPureJumpProcess::getStringParameters()
{
    return "Pure Jump Process: INTENSITY = X_T * " + std::to_string(intensityGradient_) + ", SCALE: " + std::to_string(scale_) + "\n";
}