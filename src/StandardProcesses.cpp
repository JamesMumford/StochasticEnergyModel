#include "StandardProcesses.hpp"


PoissonProcess::PoissonProcess(double intensity, double scale) : PureJumpProcess
(
    [intensity](double t, double x_t){ return intensity; },
    std::make_unique<DiracDelta>(scale)
){};