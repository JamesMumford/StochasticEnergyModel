#pragma once

class OrnsteinUhlenbeck
{
    public:
        OrnsteinUhlenbeck(double theta, double mu, double sigma);

        double drift(double x_t) const;
        double diffusion(double x_t) const;

    private:
        double theta_;
        double mu_;
        double sigma_;
};