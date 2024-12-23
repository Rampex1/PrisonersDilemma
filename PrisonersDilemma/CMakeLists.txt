cmake_minimum_required(VERSION 3.29)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled
        main.cpp
        Simulation/Battle.cpp
        Strategies/Peacemaker/Peacemaker.cpp
        Strategies/Warmonger/Warmonger.cpp
        Strategies/Warmonger/Warmonger.h
        Strategies/Peacemaker/Peacemaker.h
        Strategies/Strategy.h
        Simulation/Battle.h
        Simulation/Battle.cpp
        Strategies/Grudger/Grudger.cpp
        Strategies/Grudger/Grudger.h
        Strategies/Grudger/Grudger.cpp
        Constants.h
        Constants.cpp
        Strategies/Pendulum/Pendulum.cpp
        Strategies/Pendulum/Pendulum.h
        Strategies/TitForTat/TitForTat.cpp
        Strategies/TitForTat/TitForTat.h
        Strategies/CrowdFollower/CrowdFollower.h
        Strategies/CrowdFollower/CrowdFollower.cpp
        Strategies/Random/Random.cpp
        Strategies/Random/Random.h
        Strategies/Bully/Bully.cpp
        Strategies/Bully/Bully.h
        Strategies/Rebel/Rebel.cpp
        Strategies/Rebel/Rebel.h)
