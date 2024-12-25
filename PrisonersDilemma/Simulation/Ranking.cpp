#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

unordered_map<string, int> totalScores;

void InitializeScores(const vector<string>& strategyNames) {
    for (const auto& strategy : strategyNames) {
        totalScores[strategy] = 0;
    }
}

void UpdateScores(const string& strategyOne, const string& strategyTwo, int scoreOne, int scoreTwo) {
    totalScores[strategyOne] += scoreOne;
    totalScores[strategyTwo] += scoreTwo;
}

void RankStrategies(const vector<string>& strategyNames) {
    vector<pair<string, int>> rankedStrategies;

    // Filter valid strategies
    for (const auto& strategy : strategyNames) {
        if (totalScores.count(strategy)) {
            rankedStrategies.emplace_back(strategy, totalScores[strategy]);
        }
    }

    // Sort strategies by score in descending order
    sort(rankedStrategies.begin(), rankedStrategies.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
    });

    // Display ranked strategies
    cout << "\n=== Strategy Rankings ===\n";
    for (size_t i = 0; i < rankedStrategies.size(); ++i) {
        cout << i + 1 << ". " << rankedStrategies[i].first << ": " << rankedStrategies[i].second << " points" << endl;
    }
}