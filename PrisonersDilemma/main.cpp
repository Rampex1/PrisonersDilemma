#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>
#include <functional>
#include <vector>
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

    // Track total scores for each strategy
    unordered_map<string, int> totalScores;

    // Initialize scores to 0
    for (const auto& pair : strategyFactory) {
        totalScores[pair.first] = 0;
    }

    // Generate all strategy names
    vector<string> strategyNames;
    for (const auto& pair : strategyFactory) {
        strategyNames.push_back(pair.first);
    }

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
            totalScores[strategyOneName] += strategyOneScore;
            totalScores[strategyTwoName] += strategyTwoScore;

            // DEBUG: Print match results
            cout << strategyOneName << " vs " << strategyTwoName << " => "
                 << strategyOneScore << ":" << strategyTwoScore << endl;
        }
    }

    // Print final total scores
    cout << "\n=== Final Total Scores ===\n";
    for (const auto& pair : totalScores) {
        cout << pair.first << ": " << pair.second << endl;
    }

    // Print active strategies
    cout << "\n=== Active Strategies ===\n";
    for (size_t i = 0; i < strategyNames.size(); ++i) {
        cout << strategyNames[i] << ": " << (activeStrategies[i] ? "Active" : "Inactive") << endl;
    }

    return 0;
}
