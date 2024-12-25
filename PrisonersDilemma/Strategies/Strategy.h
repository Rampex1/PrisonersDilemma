#ifndef STRATEGY_H
#define STRATEGY_H

#include <iostream>

using namespace std;

class Strategy {
public:
    virtual int getMove() = 0;
    virtual void setNextMove(int result) = 0;
    virtual ~Strategy() {}
};

#include "./Peacemaker/Peacemaker.h"
#include "./Warmonger/Warmonger.h"
#include "./Bully/Bully.h"
#include "./CrowdFollower/CrowdFollower.h"
#include "./Grudger/Grudger.h"
#include "./Pendulum/Pendulum.h"
#include "./Random/Random.h"
#include "./Rebel/Rebel.h"
#include "./TitForTat/TitForTat.h"

#endif //STRATEGY_H
