#include "Grudger.h"
#include "../../Constants.h"
#include <iostream>
using namespace std;

int Grudger::getMove() {
  return move;
}

void Grudger::setNextMove(int result) {
  if (ROBBED_VAL == 0) move = 1;
}
