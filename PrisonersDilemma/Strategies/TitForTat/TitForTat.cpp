#include "TitForTat.h"
#include "../../Constants.h"
#include <iostream>
using namespace std;

int TitForTat::getMove() {
    return move;
}

void TitForTat::setNextMove(int result) {
    if (result == ROBBED_VAL || result == BOTH_LOSE_VAL) {
        move = 1;
    } else {
        move = 0;
    }
}
