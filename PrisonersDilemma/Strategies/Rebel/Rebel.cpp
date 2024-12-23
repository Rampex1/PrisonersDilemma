#include "Rebel.h"
#include "../../Constants.h"
#include <iostream>
using namespace std;

int Rebel::getMove() {
    return move;
}

void Rebel::setNextMove(int result) {
    if (result == ROBBED_VAL || result == BOTH_LOSE_VAL) {
        move = 0;
    } else {
        move = 1;
    }
}
