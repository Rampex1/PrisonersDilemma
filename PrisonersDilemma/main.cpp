#include <iostream>
#include "./Strategies/Peacemaker/Peacemaker.h"
#include "./Strategies/Warmonger/Warmonger.h"
#include "Simulation/Battle.h"
#include "Strategies/Bully/Bully.h"
#include "Strategies/CrowdFollower/CrowdFollower.h"
#include "Strategies/Grudger/Grudger.h"
#include "Strategies/Pendulum/Pendulum.h"
#include "Strategies/Random/Random.h"
#include "Strategies/Rebel/Rebel.h"
#include "Strategies/TitForTat/TitForTat.h"
using namespace std;

int main() {
    Warmonger warmonger;
    Peacemaker peacemaker;
    Grudger grudger;
    Pendulum pendulum;
    TitForTat tit_for_tat;
    CrowdFollower crowd_follower;
    Random random;
    Bully bully;
    Rebel rebel;

    for (int i = 1; i <= 10; i++) {
        array<int, 2> result = Battle(&peacemaker, &rebel);
        cout << "Result: [";
        for (size_t i = 0; i < result.size(); ++i) {
            cout << result[i];
            if (i < result.size() - 1) cout << ", "; // Add a comma for all but the last element
        }
        cout << "]" << endl;
        UpdateStrategy(&peacemaker, &rebel, result);
    }
}
