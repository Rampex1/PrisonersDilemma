#ifndef RANKING_H
#define RANKING_H

#include <vector>
#include <string>

void InitializeScores(const std::vector<std::string>& strategyNames);
void UpdateScores(const std::string& strategyOne, const std::string& strategyTwo, int scoreOne, int scoreTwo);
void RankStrategies(const std::vector<std::string>& strategyNames);

#endif // RANKING_H
