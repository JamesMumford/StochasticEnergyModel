#include "OrnsteinUhlenbeck.hpp"
#include "EulerMaruyama.hpp"
#include <iostream>

const int no_steps = 50;

int main()
{
    OrnsteinUhlenbeck process(50,10,5);
    EulerMaruyama solver(process,0.001,19);
    vector<double> pathHistory = solver.simulatePathHistory(5,no_steps);
    for (int i = 0; i < no_steps; i++)
    {
        std::cout << pathHistory.at(i) << "\n";
    }
};