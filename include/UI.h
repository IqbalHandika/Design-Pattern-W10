#ifndef UI_H
#define UI_H

#include <iostream>
#include <glad/glad.h>

class UI {
public:
    void updateHealth();
    void drawHealthBar(int health);
};

#endif