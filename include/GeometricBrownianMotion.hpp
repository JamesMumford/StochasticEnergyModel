#pragma once

class GeometricBrownianMotion
{
    public:
        GeomtricBrownianMotion(double mu, double sigma);

    private:
        double mu_;
        double sigma_;
};