#include <iostream>
#include "./Strategies/Peacemaker/Peacemaker.h"
#include "./Strategies/Warmonger/Warmonger.h"
#include "Simulation/Battle.h"
using namespace std;

int main() {
    Warmonger player1;
    Peacemaker player2;

    int result = Battle(&player1, &player2);
    cout << result << endl;
}