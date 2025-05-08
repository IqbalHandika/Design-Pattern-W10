#include "../include/Player.h"
#include "GameEventMediator.h"
#include <iostream>

Player::Player(GameEventMediator& mediator) : mediator(mediator) {}

void Player::attack() {
    std::cout << "Player attacks!" << std::endl;
    mediator.triggerEvent("attack");
}