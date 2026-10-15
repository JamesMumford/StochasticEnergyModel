#include "UtilityFunctions.hpp"

namespace Utility
{
    std::vector<double> parseCSVline(std::string line)
    {
        std::vector<double> returnVect(1);
        returnVect.at(0) = 1.0;
        return returnVect;
    }

    void writeEulerMaruyamaSim(StochasticProcess& OUref, double T_0, double X_T_0, double resolution, unsigned int noSteps, unsigned int noSims, unsigned int randomSeed)
    {
        std::string filename;
        std::cout << "\nStore results in file: ";
        std::cin >> filename;

        filename = "results/ou/"+filename + ".csv";

        EulerMaruyama OUsolver(OUref, resolution, randomSeed);
        OUsolver.writeSimulationParams(filename, noSteps, noSims, T_0, X_T_0);
        
        for (int i = 0; i < noSims; i++)
        {
            EulerMaruyama OUsolver(OUref, resolution, randomSeed + i);
            OUsolver.simulateAndWritePathHistory(filename, T_0, X_T_0, noSteps);
        }
    }
}

