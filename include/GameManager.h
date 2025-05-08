#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "UI.h"
#include "ScoreSystem.h"
#include "Sound.h"

class GameManager {
public:
    GameManager();
    ~GameManager();

    bool init();       // Inisialisasi game
    void run();        // Game loop
    void cleanup();    // Bersihkan resource

private:
    GLFWwindow* window;
    int health;
    UI ui;
    ScoreSystem scoreSystem;
    Sound sound;

    bool processInput(); // Input handler
    void update();       // Update game state
    void render();       // Render game
};

#endif