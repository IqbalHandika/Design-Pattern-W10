#include "UI.h"
#include <glad/glad.h>

void UI::updateHealth() {
    std::cout << "UI: Updating enemy health...\n";
}

void UI::drawHealthBar(int health) {
    std::cout << "Drawing health bar with " << health << " segments.\n";

    for (int i = 0; i < health; i++) {
        float xOffset = i * 0.25f; // Offset untuk setiap kotak
        glBegin(GL_QUADS);
        glColor3f(0.0f, 1.0f, 0.0f); // Warna hijau
        glVertex2f(-0.4f + xOffset,  0.3f); // Kiri bawah
        glVertex2f(-0.2f + xOffset,  0.3f); // Kanan bawah
        glVertex2f(-0.2f + xOffset,  0.5f); // Kanan atas
        glVertex2f(-0.4f + xOffset,  0.5f); // Kiri atas
        glEnd();
    }
}