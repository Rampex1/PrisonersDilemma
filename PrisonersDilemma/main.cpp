#include <iostream>
#include <string>
#include <unordered_map>
#include <functional>
#include <vector>
#include "./Strategies/Strategy.h"
#include "Simulation/Battle.h"
#include "Simulation/Ranking.h"

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
        {"Rebel", []() { return make_unique<Rebel>(); }}
    };

    // Vector to track which strategies are active (all 1 for now)
    vector<int> activeStrategies(strategyFactory.size(), 1);

    // Generate all strategy names
    vector<string> strategyNames;
    for (const auto& pair : strategyFactory) {
        strategyNames.push_back(pair.first);
    }

    InitializeScores(strategyNames);

    // Play matches between all combinations of active strategies
    for (size_t i = 0; i < strategyNames.size(); ++i) {
        if (activeStrategies[i] == 0) continue; // Skip inactive strategies

        for (size_t j = 0; j < strategyNames.size(); ++j) {
            if (i == j || activeStrategies[j] == 0) continue; // Skip self-play and inactive strategies

            string strategyOneName = strategyNames[i];
            string strategyTwoName = strategyNames[j];

            // Create strategy instances
            unique_ptr<Strategy> strategyOne = strategyFactory[strategyOneName]();
            unique_ptr<Strategy> strategyTwo = strategyFactory[strategyTwoName]();

            int strategyOneScore = 0;
            int strategyTwoScore = 0;

            // Play 100 rounds
            for (int round = 1; round <= 100; ++round) {
                array<int, 2> result = Battle(strategyOne.get(), strategyTwo.get());
                strategyOneScore += result[0];
                strategyTwoScore += result[1];
                UpdateStrategy(strategyOne.get(), strategyTwo.get(), result);
            }

            // Update total scores
            UpdateScores(strategyOneName, strategyTwoName, strategyOneScore, strategyTwoScore);

            // DEBUG: Print match results
            cout << strategyOneName << " vs " << strategyTwoName << " => "
                 << strategyOneScore << ":" << strategyTwoScore << endl;
        }
    }

    RankStrategies(strategyNames);

    return 0;
}