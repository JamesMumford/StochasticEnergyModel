cmake_minimum_required(VERSION 3.20)

project(StochasticEnergyModel)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(stochastic_model
    src/main.cpp
    src/OrnsteinUhlenbeck.cpp
    src/EulerMaruyama.cpp
)

target_include_directories(stochastic_model PRIVATE include)