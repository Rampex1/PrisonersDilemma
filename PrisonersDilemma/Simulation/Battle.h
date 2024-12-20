#ifndef BATTLE_H
#define BATTLE_H

#include "../Strategies/Strategy.h"
#include <array>

array<int, 2> Battle(Strategy* player1, Strategy* player2);
void UpdateStrategy(Strategy* player1, Strategy* player2, array<int, 2> result);

#endif // BATTLE_H
