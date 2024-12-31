#include <iostream>
#include <string>
#include <unordered_map>
#include <functional>
#include <vector>
#include "Constants.h"
#include "./Strategies/Strategy.h"
#include "Simulation/Battle.h"
#include "Simulation/Ranking.h"
#include "Strategies/Enforcer/Enforcer.h"

using namespace std;

int main() {
    // Map of strategy names to factory functions
    unordered_map<string, function<unique_ptr<Strategy>()>> strategyFactory = {
        {"Peacemaker", []() { return make_unique<Peacemaker>(); }},
        {"Warmonger", []() { return make_unique<Warmonger>(); }},
        {"Grudger", []() { return make_unique<Grudger>(); }},
        {"Pendulum", []() { return make_unique<Pendulum>(); }},
        {"TitForTat", []() { return make_unique<TitForTat>(); }},
        {"CrowdFollower", []() { return make_unique<CrowdFollower>(); }},
        {"Random", []() { return make_unique<Random>(); }},
        {"Bully", []() { return make_unique<Bully>(); }},
        {"Rebel", []() { return make_unique<Rebel>(); }},
        {"Enforcer", []() { return make_unique<Enforcer>(); }}
    };

    // Generate all strategy names
    vector<string> strategyNames;
    for (const auto& pair : strategyFactory) {
        strategyNames.push_back(pair.first);
    }

    InitializeScores(strategyNames);

    // Play matches between all combinations of strategies
    for (size_t i = 0; i < strategyNames.size(); ++i) {
        for (size_t j = i; j < strategyNames.size(); ++j) {
            if (i == j) continue; // Skip self-play

            string strategyOneName = strategyNames[i];
            string strategyTwoName = strategyNames[j];

            // Create strategy instances
            unique_ptr<Strategy> strategyOne = strategyFactory[strategyOneName]();
            unique_ptr<Strategy> strategyTwo = strategyFactory[strategyTwoName]();
            int strategyOneScore = 0;
            int strategyTwoScore = 0;

            // Play rounds
            for (int round = 1; round <= NUMBER_OF_ROUNDS; ++round) {
                array<int, 2> result = Battle(strategyOne.get(), strategyTwo.get());
                strategyOneScore += result[0];
                strategyTwoScore += result[1];
                UpdateStrategy(strategyOne.get(), strategyTwo.get(), result);
            }

            UpdateScores(strategyOneName, strategyTwoName, strategyOneScore, strategyTwoScore);

            // Print match results
            cout << strategyOneName << " vs " << strategyTwoName << " => "
                 << strategyOneScore << ":" << strategyTwoScore << endl;
        }
    }

    RankStrategies(strategyNames);

    return 0;
}