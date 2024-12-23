#include "Random.h"
#include <iostream>
#include <random>
using namespace std;

int Random::getMove() {
    return move;
}

void Random::setNextMove(int result) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, 1);
    int randomNumber = dist(gen);
    move = randomNumber;
}
