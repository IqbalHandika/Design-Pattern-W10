#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "GameEventMediator.h"
#include "Player.h"
#include "UI.h"
#include "Sound.h"
#include "ScoreSystem.h"

class GameManager {
public:
    GameManager();
    ~GameManager();

    void run(); // Jalankan game loop

private:
    GameEventMediator mediator;
    Player* player;
    UI ui;
    Sound sound;
    ScoreSystem scoreSystem;

    void setupListeners(); // Daftarkan listener ke mediator
    void processInput();   // Tangani input pemain
};

#endif