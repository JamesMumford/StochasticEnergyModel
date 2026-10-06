#include "OrnsteinUhlenbeck.hpp"
#include "EulerMaruyama.hpp"
#include <iostream>

int main()
{
    OrnsteinUhlenbeck process(0.1,0.1,0.1);
    EulerMaruyama solver(process,2,19);

    std::cout << solver.step(0.5);
};