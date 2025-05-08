#include "../include/GameManager.h"
#include "../include/Player.h"
#include "../include/UI.h"
#include "../include/Player.h"
#include "../include/ScoreSystem.h"
#include "../include/Sound.h"
#include "GameEventMediator.h"
#include <iostream>

GameManager::GameManager() {
    // Inisialisasi player dengan mediator
    player = new Player(mediator);

    // Daftarkan listener
    setupListeners();
}

GameManager::~GameManager() {
    delete player;
}

void GameManager::setupListeners() {
    mediator.registerListener("attack", [&]() { ui.updateHealth(); });
    mediator.registerListener("attack", [&]() { sound.playAttackSound(); });
    mediator.registerListener("attack", [&]() { scoreSystem.addScore(); });
}

void GameManager::processInput() {
    char input;
    std::cout << "Press 'a' to attack or 'q' to quit: ";
    std::cin >> input;

    if (input == 'a') {
        player->attack();
    } else if (input == 'q') {
        exit(0); // Keluar dari game
    }
}

void GameManager::run() {
    while (true) {
        processInput();
    }
}