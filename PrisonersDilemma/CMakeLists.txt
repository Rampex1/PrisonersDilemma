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
        Simulation/Battle.h)
