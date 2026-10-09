#include "UtilityFunctions.hpp"

BivariateFunction AddBivarFunc(std::vector<BivariateFunction>& funcs, std::vector<double> weights)
{
    return [funcs](double t, double x_t)
    {
        double sum = 0;
        for (BivariateFunction func : funcs)
        {
            sum += func(t,x_t);
        }
        return sum;
    };
}

