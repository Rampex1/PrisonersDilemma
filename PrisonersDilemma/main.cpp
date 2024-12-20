#include <iostream>
#include "./Strategies/Peacemaker/Peacemaker.h"
#include "./Strategies/Warmonger/Warmonger.h"
#include "Simulation/Battle.h"
#include "Strategies/Grudger/Grudger.h"
using namespace std;

int main() {
    Warmonger warmonger;
    Peacemaker peacemaker;
    Grudger grudger;

    for (int i = 1; i <= 10; i++) {
        array<int, 2> result = Battle(&warmonger, &grudger);
        cout << "Result: [";
        for (size_t i = 0; i < result.size(); ++i) {
            cout << result[i];
            if (i < result.size() - 1) cout << ", "; // Add a comma for all but the last element
        }
        cout << "]" << endl;
        UpdateStrategy(&warmonger, &grudger, result);
    }
}