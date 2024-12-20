#include <iostream>
#include "Battle.h"
#include <array>
#include "../Strategies/Strategy.h"
#include "../Constants.h"
using namespace std;

array<int, 2> Battle(Strategy* player1, Strategy* player2) {
    int player1Choice = player1->getMove();
    int player2Choice = player2->getMove();

    int result = player1Choice * 10 + player2Choice;

    switch (result) {
        case 0:
            return {SPLIT_VAL, SPLIT_VAL};
        case 10:
            return {STEAL_VAL, ROBBED_VAL};
        case 1:
            return {ROBBED_VAL, STEAL_VAL};
        case 11:
            return {BOTH_LOSE_VAL, BOTH_LOSE_VAL};
        default:
            return {0, 0};
    }
}

void UpdateStrategy(Strategy* player1, Strategy* player2, array<int, 2> result) {
    player1->setNextMove(result[0]);
    player2->setNextMove(result[1]);
}