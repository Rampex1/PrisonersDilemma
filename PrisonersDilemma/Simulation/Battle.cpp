#include <iostream>
#include "Battle.h"
#include "../Strategies//Strategy.h"
using namespace std;

int Battle(Strategy* player1, Strategy* player2) {
    int player1Choice = player1->getNextMove();
    int player2Choice = player2->getNextMove();

    switch (int result = player1Choice * 10 + player2Choice) {
        case 0:
            return 00;
        case 10:
            return 10;
        case 1:
            return 01;
        case 11:
            return 11;
    }

    return 0;
}