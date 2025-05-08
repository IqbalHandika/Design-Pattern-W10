#ifndef SCORESYSTEM_H
#define SCORESYSTEM_H

#include <iostream>

class ScoreSystem {
private:
    int score;

public:
    ScoreSystem();
    void addScore(int points);
    void displayScore();
};

#endif