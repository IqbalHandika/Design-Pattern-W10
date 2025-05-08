#ifndef PLAYER_H
#define PLAYER_H

#include "GameEventMediator.h"

class Player {
public:
    Player(GameEventMediator& mediator);
    void attack();

private:
    GameEventMediator& mediator;
};

#endif