#include "GeometricBrownianMotion.hpp"

GeometricBrownianMotion::GeometricBrownianMotion(double mu, double sigma) : mu_(mu), sigma_(sigma){};

double GeometricBrownianMotion::drift(double x_t)
{
    return mu_;
};

double GeometricBrownianMotion::diffusion(double x_t)
{
    return sigma_;
}