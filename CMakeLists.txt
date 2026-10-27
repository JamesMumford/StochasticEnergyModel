cmake_minimum_required(VERSION 3.20)

project(StochasticEnergyModel)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(gbm_model
    experiments/gbm/main.cpp
    src/EulerMaruyama.cpp
    src/BrownianMotion.cpp
    src/Distribution.cpp
    src/GeometricBrownianMotion.cpp
    src/StochasticProcess.cpp
    src/StandardDistributions.cpp
    src/Solver.cpp
    src/UtilityFunctions.cpp
    src/DynamicDistribution.cpp
)

add_executable(ou_model
    experiments/ou/main.cpp
    src/EulerMaruyama.cpp
    src/OrnsteinUhlenbeck.cpp
    src/Distribution.cpp
    src/BrownianMotion.cpp
    src/StochasticProcess.cpp
    src/StandardDistributions.cpp
    src/Solver.cpp
    src/UtilityFunctions.cpp
    src/DynamicDistribution.cpp
)

add_executable(jump_model
    experiments/jump/main.cpp
    src/EulerMaruyama.cpp
    src/PureJumpProcess.cpp
    src/Distribution.cpp
    src/BrownianMotion.cpp
    src/StochasticProcess.cpp
    src/StandardDistributions.cpp
    src/Solver.cpp
    src/UtilityFunctions.cpp
    src/PureJumpProcess.cpp
    src/StandardProcesses.cpp
    src/DynamicDistribution.cpp
)

add_executable(inference
    experiments/inference/main.cpp
    src/EulerMaruyama.cpp
    src/PureJumpProcess.cpp
    src/GeometricBrownianMotion.cpp
    src/OrnsteinUhlenbeck.cpp
    src/Distribution.cpp
    src/BrownianMotion.cpp
    src/StochasticProcess.cpp
    src/StandardDistributions.cpp
    src/Solver.cpp
    src/UtilityFunctions.cpp
    src/DynamicDistribution.cpp
)

add_executable(NESO_fitting
    experiments/NESO_analysis/main.cpp
    src/EulerMaruyama.cpp
    src/PureJumpProcess.cpp
    src/GeometricBrownianMotion.cpp
    src/OrnsteinUhlenbeck.cpp
    src/Distribution.cpp
    src/BrownianMotion.cpp
    src/StochasticProcess.cpp
    src/StandardDistributions.cpp
    src/Solver.cpp
    src/UtilityFunctions.cpp
    src/DynamicDistribution.cpp
)

add_executable(NESO_model
    experiments/NESO_model/main.cpp
    src/EulerMaruyama.cpp
    src/PureJumpProcess.cpp
    src/GeometricBrownianMotion.cpp
    src/OrnsteinUhlenbeck.cpp
    src/Distribution.cpp
    src/BrownianMotion.cpp
    src/StochasticProcess.cpp
    src/StandardDistributions.cpp
    src/Solver.cpp
    src/UtilityFunctions.cpp
    src/DynamicDistribution.cpp
)

add_executable(data_cleaning
    data/processing/main.cpp
)

target_include_directories(gbm_model PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(ou_model PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(jump_model PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(inference PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(NESO_fitting PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(NESO_model PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)