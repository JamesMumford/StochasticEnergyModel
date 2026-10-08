#include "OrnsteinUhlenbeck.hpp"

OrnsteinUhlenbeck::OrnsteinUhlenbeck(double theta,double mu,double sigma) : theta_(theta), mu_(mu), sigma_(sigma){}

double OrnsteinUhlenbeck::drift(double x_t) const
{
    return theta_ * (mu_ - x_t);
};

double OrnsteinUhlenbeck::diffusion(double x_t) const
{
    return sigma_;
};