#include "ScoreSystem.h"

ScoreSystem::ScoreSystem() : score(0) {}

void ScoreSystem::addScore(int points) {
    score += points;
    std::cout << "ScoreSystem: Adding score. Total: " << score << "\n";
}

void ScoreSystem::displayScore() {
    std::cout << "Score: " << score << "\n";
}