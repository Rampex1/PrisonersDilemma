#include "Pendulum.h"
#include <iostream>
using namespace std;

int Pendulum::getMove() {
    return move;
}

void Pendulum::setNextMove(int result) {
    if (getMove() == 0) {
        move = 1;
    } else {
        move = 0;
    }
}
