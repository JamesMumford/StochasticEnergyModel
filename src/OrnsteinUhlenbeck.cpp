#include "OrnsteinUhlenbeck.hpp"

OrnsteinUhlenbeck::OrnsteinUhlenbeck(double theta,double mu,double sigma) : theta_(theta), mu_(mu), sigma_(sigma){}

double OrnsteinUhlenbeck::drift(double x_t) const
{
    return -theta_ * (x_t - mu_);
};

double OrnsteinUhlenbeck::diffusion(double x_t) const
{
    return sigma_;
};