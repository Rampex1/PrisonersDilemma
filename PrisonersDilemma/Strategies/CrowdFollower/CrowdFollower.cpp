#include "CrowdFollower.h"
#include "../../Constants.h"
#include <iostream>
using namespace std;

int CrowdFollower::getMove() {
    return move;
}

void CrowdFollower::setNextMove(int result) {
    if (result == STEAL_VAL || result == SPLIT_VAL) {
        splits += 1;
    } else {
        steals += 1;
    }

    if (splits >= steals) {
        move = 0;
    } else {
        move = 1;
    }
}
