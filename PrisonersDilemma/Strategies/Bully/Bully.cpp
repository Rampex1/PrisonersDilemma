#include "Bully.h"
using namespace std;
#include "../../Constants.h"

int Bully::getMove() {
    return move;
}

void Bully::setNextMove(int result) {
    if (history_count < 1) {
        if (result == BOTH_LOSE_VAL) {
            defect_count++;
        }
        history_count++;
    } else {
        if (defect_count == 1) {
            move = 1;
        } else {
            move = 0;
        }
    }
}