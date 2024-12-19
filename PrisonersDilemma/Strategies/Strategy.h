#ifndef STRATEGY_H
#define STRATEGY_H

#include <iostream>
using namespace std;

class Strategy {
public:
    virtual int getNextMove() = 0;
    virtual ~Strategy() {}
};

#endif //STRATEGY_H
