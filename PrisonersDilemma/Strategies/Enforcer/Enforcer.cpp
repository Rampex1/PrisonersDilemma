#include "Enforcer.h"
#include "../../Constants.h"
#include <iostream>
using namespace std;

int Enforcer::getMove() {
    return move;
}

void Enforcer::setNextMove(int result) {
    if (result == ROBBED_VAL || result == BOTH_LOSE_VAL) {
        retaliationCount += 2;
    }

    if (retaliationCount > 0) {
        retaliationCount--;
        move = 1;
    } else {
        move = 0;
    }
}
