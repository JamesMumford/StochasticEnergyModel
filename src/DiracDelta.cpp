#include "DiracDelta.hpp"

DiracDelta::DiracDelta(double x) : x_(x){};

double DiracDelta::sample()
{
    return x_;
}