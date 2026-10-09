#include "PureJumpProcess.hpp"

PureJumpProcess::PureJumpProcess(Distribution& jumpWaitingDistribution, Distribution& jumpSizeDistribution) : StochasticProcess
(
    [](double,double){return 0;},
    [](double,double){return 0;},
    jumpWaitingDistribution,
    jumpSizeDistribution
){};